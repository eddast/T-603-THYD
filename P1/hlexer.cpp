// SC-T-603-THYD Fall 2018. Project part I.
#include "hlexer.h"

using namespace std;

HLexer::HLexer( std::istream& is  )
    : Lexer( is ), line_no_(1)
{
    is_.get( c_ );
}

void HLexer::match_error(Token& token){
    token.type = Tokentype::ErrUnknown;
    token.lexeme.push_back(c_);
    is_.get(c_);
}

void HLexer::match_digit(Token& token){
    while(isdigit(c_)){
        token.lexeme.push_back(c_);
        c_ = is_.get();
    }
}


void HLexer::match_real(Token& token){
    token.lexeme.push_back(c_);
    c_ = is_.get();

    if(isdigit(c_)){
        token.type = Tokentype::RealValue;
        match_digit(token);
        if(c_ == 'E'){
            token.lexeme.push_back(c_);
            c_ = is_.get();

            if(c_ == '+' || c_ == '-'){
                token.lexeme.push_back(c_);
                c_ = is_.get();
            }
            if(isdigit(c_)){
                token.type = Tokentype::RealValue;
                match_digit(token);
            } else { match_error(token); }
        }
    } else {  match_error(token); }
}

void HLexer::match_multiline(Token& token){
    token.lexeme.clear();
    while(true){
        if ( c_ == '\n' ) {
            ++line_no_;
        }
        if(c_ == '*'){
            c_ = is_.get();
            if(c_ == '/'){
                c_ = is_.get();
                break;
            }
        }
        c_ = is_.get();
    }
}

void HLexer::match_singleline(Token& token){
    token.lexeme.clear();
    while(true){
        if(c_ == '\n'){
             ++line_no_;
            c_ = is_.get();
            break;
        }
        c_ = is_.get();
    }
}


void HLexer::get_next( Token& token )
{
    token.lexeme.clear();

    while ( is_.good() && isspace(c_) ) {
        if ( c_ == '\n' ) { ++line_no_; }
        is_.get(c_);
    }

    token.line = line_no_;
    token.type = Tokentype::ErrUnknown;

    if ( !is_.good() ) {
        token.type = Tokentype::EOI;
        return;
    }

    switch ( c_ ) {
        /* Comments */
        case '/':
            std::cout << "1" << std::endl;
            token.lexeme.push_back(c_);
            is_.get(c_);
            std::cout << "token now: " << static_cast<char>(c_) << std::endl;
            if(c_ == '*'){
                match_multiline(token);
            } else if(c_ == '/'){
                std::cout << "2" << std::endl;
                match_singleline(token);
            } else {
                token.type = Tokentype::OpArtDiv;
                break;
            }

        case '\n':
            ++line_no_;
            while ( is_.good() && isspace(c_) ) {
                if ( c_ == '\n' ) { ++line_no_; }
                is_.get(c_);
            }

        /* Punctuation */
        case '{':
            token.type = Tokentype::ptLBrace;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case '}':
            token.type = Tokentype::ptRBrace;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case '[':
            token.type = Tokentype::ptLBracket;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case ']':
            token.type = Tokentype::ptRBracket;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case '(':
            token.type = Tokentype::ptLParen;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case ')':
            token.type = Tokentype::ptRParen;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case ';':
            token.type = Tokentype::ptSemicolon;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case ',':
            token.type = Tokentype::ptComma;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;



            /* Logical operators */
        case '&':
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '&'){
                token.type = Tokentype::OpLogAnd;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
            /* Logical operators */
        case '|':
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '|'){
                token.type = Tokentype::OpLogOr;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;

            /* Relational operators */
        case '=':
            token.type = Tokentype::OpAssign;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '='){
                token.type = Tokentype::OpRelEQ;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
        case '!':
            token.type = Tokentype::OpLogNot;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '='){
                token.type = Tokentype::OpRelNEQ;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
        case '<':
            token.type = Tokentype::OpRelLT;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '='){
                token.type = Tokentype::OpRelLTE;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
        case '>':
            token.type = Tokentype::OpRelGT;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '='){
                token.type = Tokentype::OpRelGTE;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;

            /* Arithmetic operators */
        case '+':
            token.type = Tokentype::OpArtPlus;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '+'){
                token.type = Tokentype::OpArtInc;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
        case '-':
            token.type = Tokentype::OpArtMinus;
            token.lexeme.push_back(c_);
            is_.get(c_);
            if(c_ == '-'){
                token.type = Tokentype::OpArtDec;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }
            break;
        case '*':
            token.type = Tokentype::OpArtMult;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case '%':
            token.type = Tokentype::OpArtModulus;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;



        default:
            /* Matching int and real*/
            if( isdigit(c_) ){
                token.type = Tokentype::IntValue;
                match_digit(token);
                if(c_ == '.'){
                    match_real(token);
                }
            }


            else if ( isalpha(c_) || (c_ == '_')){
                while( isalpha(c_) ){
                    token.type = Tokentype::Identifier;
                    token.lexeme.push_back(c_);

                    if( token.lexeme == "class"){ token.type = Tokentype::kwClass; }
                    if( token.lexeme == "static"){ token.type = Tokentype::kwStatic; }
                    if( token.lexeme == "void"){ token.type = Tokentype::kwVoid; }
                    if( token.lexeme == "if"){ token.type = Tokentype::kwIf;}
                    if( token.lexeme == "else"){ token.type = Tokentype::kwElse; }
                    if( token.lexeme == "for"){ token.type = Tokentype::kwFor; }
                    if( token.lexeme == "return"){ token.type = Tokentype::kwReturn; }
                    if( token.lexeme == "break"){ token.type = Tokentype::kwBreak; }
                    if( token.lexeme == "continue"){ token.type = Tokentype::kwContinue; }
                    if( token.lexeme == "int"){ token.type = Tokentype::kwInt; }
                    if( token.lexeme == "real"){ token.type = Tokentype::kwReal; }
                    if( token.lexeme == "bool"){ token.type = Tokentype::kwBool; }
                    if( token.lexeme == "true"){ token.type = Tokentype::BoolValue; }
                    if( token.lexeme == "false"){ token.type = Tokentype::BoolValue; }

                    is_.get(c_);
                }
                while( isalpha(c_) || isdigit(c_) || (c_ == '_')){
                    token.type = Tokentype::Identifier;
                    token.lexeme.push_back(c_);
                    is_.get(c_);
                }

            }


            else{  match_error(token); }

            break;
    }
}




std::string HLexer::get_name() const {
    return "handmade";
}

HLexer::~HLexer()
{
}
