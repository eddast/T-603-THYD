// SC-T-603-THYD Fall 2018. Project part I.
#include "hlexer.h"

using namespace std;

HLexer::HLexer( std::istream& is  )
    : Lexer( is ), line_no_(1)
{
    is_.get( c_ );
}


void HLexer::get_next( Token& token )
{
    token.lexeme.clear();

    while ( is_.good() && isspace(c_) ) {
        if ( c_ == '\n' ) { ++line_no_; }
        is_.get(c_);
    }

    token.line = line_no_;

    if ( !is_.good() ) {
        token.type = Tokentype::EOI;
        return;
    }


    switch ( c_ ) {
        /* punctuation */
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
            token.type = Tokentype::ptLBrace;
            token.lexeme.push_back(c_);
            is_.get(c_);
            break;
        case ']':
            token.type = Tokentype::ptRBrace;
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

        default:
            if( isdigit(c_) ){
                while(isdigit(c_)){
                    token.type = Tokentype::IntValue;
                    token.lexeme.push_back(c_);
                    c_ = is_.get();
                }
            }
            else{
                token.type = Tokentype::ErrUnknown;
                token.lexeme.push_back(c_);
                is_.get(c_);
            }

            break;
    }
}

std::string HLexer::get_name() const {
    return "handmade";
}

HLexer::~HLexer()
{
}
