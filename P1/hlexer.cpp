// SC-T-603-THYD Fall 2018. Project part I.
#include <map>
#include "hlexer.h"

using namespace std;

/* Initialize Lexer with input stream and line number */
HLexer::HLexer( std::istream& is  )
    : Lexer( is ), line_no_(1)
{
    is_.get( c_ );
}

/* A map of all characters and their token types that can be determined unrelated to next token */
map<int, Tokentype> SINGLETON_TOKENS =
{
    {'{', Tokentype::ptLBrace},     {'}', Tokentype::ptRBrace},     {'[', Tokentype::ptLBracket},
    {']', Tokentype::ptRBracket},   {'(', Tokentype::ptLParen},     {')', Tokentype::ptRParen},
    {';', Tokentype::ptSemicolon},  {',', Tokentype::ptComma},      {'*', Tokentype::OpArtMult},
    {'%', Tokentype::OpArtModulus}
};

/* A map of all keywords Decaf recognizes and their token types */
map<std::string, Tokentype> KEYWORD_TOKENS =
{
    {"class", Tokentype::kwClass},      {"static", Tokentype::kwStatic},    {"void", Tokentype::kwVoid},
    {"if", Tokentype::kwIf},            {"else", Tokentype::kwElse},        {"for", Tokentype::kwFor},
    {"return", Tokentype::kwReturn},    {"break", Tokentype::kwBreak},      {"continue", Tokentype::kwContinue},
    {"int", Tokentype::kwInt},          {"real", Tokentype::kwReal},        {"bool", Tokentype::kwBool},
    {"true", Tokentype::BoolValue},     {"false", Tokentype::BoolValue},
};

/* Initializes token */
void initialize_token ( Token& token, int line_no_ )
{
    token.lexeme.clear();
    token.line = line_no_;
    token.type = Tokentype::ErrUnknown;
}

/* Strips input of whitespaces */
void HLexer::strip_whitespace( Token& token )
{
    while ( is_.good() && isspace(c_) ) {
        if ( c_ == '\n' ) { ++line_no_; }
        is_.get(c_);
    }
}

/* Strips input of a multi line comment */
void HLexer::strip_multi_line_comment( Token& token )
{
    /* token should be re-initialized */
    initialize_token( token, line_no_ );
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
        strip_whitespace( token );
    }
}
/* Strips input of a single line comment */
void HLexer::strip_single_line_comment( Token& token )
{
    initialize_token( token, line_no_ );
    while ( true ) {
        if(c_ == '\n'){
            ++line_no_;
            c_ = is_.get();
            break;
        }
        c_ = is_.get();
    }
    strip_whitespace( token );
}

/* Matches token as an unknown token */
void HLexer::match_unknown( Token& token )
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
    match_unknown(token);
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
    initialize_token( token, line_no_ );

    // Strip whitespaces encountered
    strip_whitespace( token );

    // Encountering a '/' is a special case:
    // Can denote division operator if stand-alone
    // Can denote comment in case of following '*' or '/'
    if( c_ == '/' ) {
        token.type = Tokentype::OpArtDiv;
        token.lexeme.push_back(c_);
        is_.get(c_);
        if (c_ == '*')      {   strip_multi_line_comment(token);    }
        else if (c_ == '/') {   strip_single_line_comment(token);   }
        else return;
    }

    switch ( c_ ) {

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

        default:

            // Matching all tokens that can unambiguously be matched
            // I.e. singleton tokens whose token type can be determined without looking at next character
            std::map<int,Tokentype>::iterator singletonToken = SINGLETON_TOKENS.find(c_);
            if ( singletonToken != SINGLETON_TOKENS.end() ) {
                token.type = singletonToken->second;
                token.lexeme.push_back(c_);
                is_.get(c_);
                return;
            }

            // Matching all possible numerical values encountered
            // Regarded as int value unless fraction is encountered, then as real value
            else if( isdigit(c_) ) {
                token.type = Tokentype::IntValue;
                match_digit(token);
                match_real(token);
                return;
            }

            // Matching all word values encountered that start with character or underscore
            // Regarded as identifier unless it matches a known keyword in language in full
            else if( isalpha(c_) || c_ == '_' ) {

                while( isalpha(c_) ) {
                    token.type = Tokentype::Identifier;
                    token.lexeme.push_back(c_);

                    // Match lexeme as a keyword token if appropriate
                    map<string, Tokentype>::iterator keyword = KEYWORD_TOKENS.find(token.lexeme);
                    if ( keyword != KEYWORD_TOKENS.end() ) {
                        token.type = keyword->second;
                    }
                    is_.get(c_);
                }

                // Identifier can also include digit or underscore
                while( isalpha(c_) || isdigit(c_) || c_ == '_' ) {
                    token.type = Tokentype::Identifier;
                    token.lexeme.push_back(c_);
                    is_.get(c_);
                }
                return;
            }

            // If no condition applies or returns,
            // We assume token is unknown
            match_unknown( token );
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
