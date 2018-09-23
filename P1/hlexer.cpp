/***********************************************************
 *      SC-T-603-THYD Fall 2018
 *      Assignment: Project part I
 *      Due: 24th of September 2018
 *      Part: Section 1 Handwritten Lexer (Implementation)
 *      Authors:
 *          Edda Pétursdóttir
 *          Edda Steinunn Rúnarsdóttir
 *****************************************************+****/

#include "hlexer.h"
#include <map>

/* Initialize Lexer with input stream and line number */
HLexer::HLexer( std::istream& is  )
    : Lexer( is ), line_no_(1)
{
    is_.get( c_ );
}

/* A map of all characters to their token types that can be determined unrelated to next token */
std::map<int, Tokentype> SINGLETON_TOKENS =
{
    {'{', Tokentype::ptLBrace},     {'}', Tokentype::ptRBrace},     {'[', Tokentype::ptLBracket},
    {']', Tokentype::ptRBracket},   {'(', Tokentype::ptLParen},     {')', Tokentype::ptRParen},
    {';', Tokentype::ptSemicolon},  {',', Tokentype::ptComma},      {'*', Tokentype::OpArtMult},
    {'%', Tokentype::OpArtModulus}
};

/* A map of all keywords Decaf recognizes to their token types */
std::map<std::string, Tokentype> KEYWORD_TOKENS =
{
    {"class", Tokentype::kwClass},      {"static", Tokentype::kwStatic},    {"void", Tokentype::kwVoid},
    {"if", Tokentype::kwIf},            {"else", Tokentype::kwElse},        {"for", Tokentype::kwFor},
    {"return", Tokentype::kwReturn},    {"break", Tokentype::kwBreak},      {"continue", Tokentype::kwContinue},
    {"int", Tokentype::kwInt},          {"real", Tokentype::kwReal},        {"bool", Tokentype::kwBool},
    {"true", Tokentype::BoolValue},     {"false", Tokentype::BoolValue},
};

/* a struct of ambigous token matches */
/* i.e. the first and second characters in ambiguous prefix and their first and second choice token type matches */
struct Ambigous_Token_Matches {
    Ambigous_Token_Matches( int first, int second, Tokentype first_match, Tokentype second_match ) :
            first( first ), second( second ), first_match( first_match ), second_match( second_match ) {}
    int first;
    int second;
    Tokentype first_match;
    Tokentype second_match;
};

/* A map of all sets of characters and their token types that cannot be determined unrelated to next token */
std::map<int, Ambigous_Token_Matches> AMBIGOUS_TOKENS =
{
    {'&',    Ambigous_Token_Matches('&', '&', Tokentype::ErrUnknown, Tokentype::OpLogAnd)},
    {'|',    Ambigous_Token_Matches('|', '|', Tokentype::ErrUnknown, Tokentype::OpLogOr)},
    {'=',    Ambigous_Token_Matches('=', '=', Tokentype::OpAssign, Tokentype::OpRelEQ)},
    {'!',    Ambigous_Token_Matches('!', '=', Tokentype::OpLogNot, Tokentype::OpRelNEQ)},
    {'<',    Ambigous_Token_Matches('<', '=', Tokentype::OpRelLT, Tokentype::OpRelLTE)},
    {'>',    Ambigous_Token_Matches('>', '=', Tokentype::OpRelGT, Tokentype::OpRelGTE)},
    {'+',    Ambigous_Token_Matches('+', '+', Tokentype::OpArtPlus, Tokentype::OpArtInc)},
    {'-',    Ambigous_Token_Matches('-', '-', Tokentype::OpArtMinus, Tokentype::OpArtDec)},
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
        if ( c_ == '\n' ) {
            ++line_no_;
            token.line = line_no_;
        }
        is_.get(c_);
    }
}

/* Strips out comments */
void HLexer::strip_multi_line_comment( Token& token )
{
    /* token should be re-initialized */
    initialize_token( token, line_no_ );
    while( true ) {
        if( c_ == '\n' ) {
            ++line_no_;
            token.line = line_no_;
        }
        if( c_ == '*' ) {
            c_ = is_.get();
            if(c_ == '/'){
                c_ = is_.get();
                break;
            }
        } else {
            c_ = is_.get();
        }
    }
    strip_whitespace( token );
}

/* Strips input of a single line comment */
void HLexer::strip_single_line_comment( Token& token )
{
    initialize_token( token, line_no_ );
    while ( true ) {
        if(c_ == '\n') {
            ++line_no_;
            token.line = line_no_;
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

    // If real value is badly formatted, i.e. includes alphabetic letters or something (f.x. 12EEBB, raise error
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
    while( c_ == '/' ) {
        token.type = Tokentype::OpArtDiv;
        token.lexeme.push_back(c_);
        is_.get(c_);
        if (c_ == '*')      {   strip_multi_line_comment(token);    }
        else if (c_ == '/') {   strip_single_line_comment(token);   }
        else return;
    }

    // Matching all possible numerical values encountered
    // Regarded as int value unless fraction is encountered, then as real value
    if( isdigit(c_) ) {
        token.type = Tokentype::IntValue;
        match_digit(token);
        match_real(token);
        return;
    }

    // Matching all word values encountered that start with character or underscore
    // Regarded as identifier unless it matches a known keyword (or "true"/"false") in Decaf's language in full
    else if( isalpha(c_) || c_ == '_' ) {

        while( isalpha(c_) ) {
            token.type = Tokentype::Identifier;
            token.lexeme.push_back(c_);
            std::map<std::string, Tokentype>::iterator keyword = KEYWORD_TOKENS.find(token.lexeme);
            if ( keyword != KEYWORD_TOKENS.end() ) {
                token.type = keyword->second;
            }
            is_.get(c_);
        }

        // Consume token as Identifier when digit or underscore is encountered as well
        while( isalpha(c_) || isdigit(c_) || c_ == '_' ) {
            token.type = Tokentype::Identifier;
            token.lexeme.push_back(c_);
            is_.get(c_);
        }

        return;
    }

    // Matching all the singleton tokens that can unambiguously be matched
    // I.e. the tokens whose token type can be determined without having to look at next character in stream
    std::map<int, Tokentype>::iterator singletonToken = SINGLETON_TOKENS.find(c_);
    if ( singletonToken != SINGLETON_TOKENS.end() ) {
        token.type = singletonToken->second;
        token.lexeme.push_back(c_);
        is_.get(c_);

        return;
    }

    // Matching all the tokens that cannot unambiguously be matched
    // I.e. the tokens whose token type can only be determined by looking at next character in stream
    std::map<int, Ambigous_Token_Matches>::iterator ambigousToken = AMBIGOUS_TOKENS.find(c_);
    if ( ambigousToken != AMBIGOUS_TOKENS.end() ) {

        // Match first choice of token type
        token.type = ambigousToken->second.first_match;
        token.lexeme.push_back(c_);
        is_.get(c_);

        // If the second character that changes token type is encountered, match second choice of token type
        if( c_ == ambigousToken->second.second ) {
            token.type = ambigousToken->second.second_match;
            token.lexeme.push_back(c_);
            is_.get(c_);
        }

        return;
    }

    // If no condition applies or returns,
    // We assume token is unknown
    match_unknown( token );
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
