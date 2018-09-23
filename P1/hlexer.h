// SC-T-603-THYD Fall 2018. Project part I.
#ifndef LEXER_HLEXER_H
#define LEXER_HLEXER_H

#include "lexer.h"

class HLexer : public Lexer {
public:
    HLexer( std::istream& is );

    virtual void get_next( Token& token );
    virtual std::string get_name() const;
    virtual void strip_whitespace( Token& token );
    virtual void strip_multi_line_comment( Token& token );
    virtual void strip_single_line_comment( Token& token );
    virtual void match_unknown( Token& token );
    virtual void match_digit( Token& token );
    virtual void match_real( Token& token );

    virtual ~HLexer();
private:
    char c_;
    int  line_no_;
};

#endif //LEXER_HLEXER_H
