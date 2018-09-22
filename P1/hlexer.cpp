// SC-T-603-THYD Fall 2018. Project part I.
#include "hlexer.h"

using namespace std;

/* Initilize Lexer with input stream and line number */
HLexer::HLexer( std::istream& is  )
    : Lexer( is ), line_no_(1)
{
    is_.get( c_ );
}

/* Strips input of whitespaces */
void HLexer::strip_whitespaces( Token& token )
{
    while ( is_.good() && isspace(c_) ) {
        if ( c_ == '\n' ) { ++line_no_; }
        is_.get(c_);
    }
}

/* Strips input of multi line comment */
void HLexer::strip_multi_line_comment( Token& token )
{
    initialize_token( token );
    while( true ) {
        if ( c_ == '\n' ) { ++line_no_; }
        if(c_ == '*'){
            c_ = is_.get();
            if(c_ == '/'){
                c_ = is_.get();
                break;
            }
        }
        c_ = is_.get();
        strip_whitespaces();
    }
}
/* Strips input of single line comments */
void HLexer::strip_single_line_comment( Token& token )
{
    initialize_token( token );
    while ( true ) {
        if(c_ == '\n'){
            ++line_no_;
            c_ = is_.get();
            break;
        }
        c_ = is_.get();
        strip_whitespaces();
    }
}

/* Matches token as an unknown token */
void HLexer::match_error( Token& token )
{
    token.type = Tokentype::ErrUnknown;
    token.lexeme.push_back(c_);
    is_.get(c_);
}

/* Helper function, matches and adds a digit [0-9]+ */
void HLexer::match_digit( Token& token )
{
    while( isdigit(c_) ) {
        token.lexeme.push_back(c_);
        c_ = is_.get();
    }
}

/* Matches a real value */
void HLexer::match_real( Token& token )
{
    // Mandatory fraction part after digit part
    if( c_ != '.' ) return;
    token.lexeme.push_back(c_);
    c_ = is_.get();

    // At least one digit is present after fraction
    if( isdigit(c_) ) {
        token.type = Tokentype::RealValue;
        match_digit(token);

        // match optional exponent part
        if( c_ == 'E' ) {
            token.lexeme.push_back(c_);
            c_ = is_.get();
            if( c_ == '+' || c_ == '-' ) {
                token.lexeme.push_back(c_);
                c_ = is_.get();
            }
            if( isdigit(c_) ) {
                token.type = Tokentype::RealValue;
                match_digit(token);
                return;
            }
        }
        else return;
    }
    match_error(token);
}

/* Initilizes token */
void initialize_token ( Token& token )
{
    token.lexeme.clear();
    token.line = line_no_;
    token.type = Tokentype::ErrUnknown;
}

/* Match and scan type of next token */
void HLexer::get_next( Token& token )
{
    // Stop scanning on end of input
    if ( !is_.good() ) {
        token.type = Tokentype::EOI;
        return;
    }

    // Initialize token for next iteration
    initialize_token( token );

    // Strip whitespaces encountered
    strip_whitespaces( token );

    switch ( c_ ) {

        // Encountering a '/' can denote either division operator if standalone
        // Or syntax comments in case of another '*' or '/' in which are stripped
        case '/':

            token.type = Tokentype::OpArtDiv;
            token.lexeme.push_back(c_);
            is_.get(c_);

            if( c_ == '*' ) strip_multi_line_comment(token);
            else if( c_ == '/' ) strip_single_line_comment(token);
            else break;

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

            // Matching all possible numerical values encountered
            // Regarded as int value unless fraction is encountered, then as real value
            if( isdigit(c_) ) {
                token.type = Tokentype::IntValue;
                match_digit(token);
                match_real(token);
                return;
            }

            // Matching all word values encountered
            // Regarded as identifier unless it matches a known keyword in language in full
            else if ( isalpha(c_) || (c_ == '_') ) {

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
                while( isalpha(c_) || isdigit(c_) || (c_ == '_') ) {
                    token.type = Tokentype::Identifier;
                    token.lexeme.push_back(c_);
                    is_.get(c_);
                }
                return;
            }
            match_error(token);
    }
}

/* Get lexer's name */
std::string HLexer::get_name() const
{
    return "handmade";
}

/* Destructor */
HLexer::~HLexer()
{

}
