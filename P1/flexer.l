/*******************************************
 * SC-T-603-THYD Fall 2018
 * Assignment: Project part I
 * Due: 24th of September 2018
 * Part: section 2 flexer
 * Authors:
 *  Edda Pétursdóttir
 *  Edda Steinunn Rúnarsdóttir
 ***************************************+***/


%option c++
%option noyywrap
%option yylineno
%{
#include "token.h"
%}

/* private rules */
num         [0-9]
int         {num}+
charUpper   [A-Z]
charLower   [a-z]
char        {charUpper}|{charLower}
exponent    E(\+|-)?({int})+
frac        \.{int}

/* ids and variable type recognizers */
identifier  ({char}|\_)+({num}|{char}|\_)*
real        {int}{frac}({exponent})?
bool        true|false

/* relational */
eqop        ==
noteqop     !=
lessop      <
lesseqop    <=
greaterop   >
greatereqop >=

/* arithmetic */
incrementop \+\+
decrementop \-\-
plusop      \+
minusop     \-
multop      \*
divop       \/
modop       %

/* logical */
andop       &&
orop        \|\|
notop       !

/* assignment */
assignmentop =

/* keywords */
kwclass     class
kwstatic    static
kwvoid      void
kwif        if
kwelse      else
kwfor       for
kwreturn    return
kwbreak     break
kwcontinue  continue
kwint       int
kwreal      real
kwbool      bool

/* punctuation */
ws          [ \t\r\n]
lbrace      \{
rbrace      \}
lbracket    \[
rbracket    \]
lparen      \(
rparen      \)
semicolon   \;
comma       \,

multicomment     \/\*([^*]|(\*+[^*/]))*\*+\/
singlecomment    \/\/.*\n



%%
    /** match punctuation **/

{multicomment}  { return Tokentype::ptLBrace; }
{singlecomment} { return Tokentype::ptLBrace; }
{ws}+
{lbrace}        { return Tokentype::ptLBrace; }
{rbrace}        { return Tokentype::ptRBrace; }
{lbracket}      { return Tokentype::ptLBracket; }
{rbracket}      { return Tokentype::ptRBracket; }
{lparen}        { return Tokentype::ptLParen; }
{rparen}        { return Tokentype::ptRParen; }
{semicolon}     { return Tokentype::ptSemicolon; }
{comma}         { return Tokentype::ptComma; }

    /** match keywords **/
{kwclass}       { return Tokentype::kwClass; }
{kwstatic}      { return Tokentype::kwStatic; }
{kwvoid}        { return Tokentype::kwVoid; }
{kwif}          { return Tokentype::kwIf; }
{kwelse}        { return Tokentype::kwElse; }
{kwfor}         { return Tokentype::kwFor; }
{kwreturn}      { return Tokentype::kwReturn; }
{kwbreak}       { return Tokentype::kwBreak; }
{kwcontinue}    { return Tokentype::kwContinue; }
{kwint}         { return Tokentype::kwInt; }
{kwreal}        { return Tokentype::kwReal; }
{kwbool}        { return Tokentype::kwBool; }

    /** match operators **/
{eqop}          { return Tokentype::OpRelEQ; }
{noteqop}       { return Tokentype::OpRelNEQ; }
{lesseqop}      { return Tokentype::OpRelLTE; }
{greatereqop}   { return Tokentype::OpRelGTE; }
{lessop}        { return Tokentype::OpRelLT; }
{greaterop}     { return Tokentype::OpRelGT; }
{andop}         { return Tokentype::OpLogAnd; }
{orop}          { return Tokentype::OpLogOr; }
{notop}         { return Tokentype::OpLogNot; }
{incrementop}   { return Tokentype::OpArtInc; }
{decrementop}   { return Tokentype::OpArtDec; }
{plusop}        { return Tokentype::OpArtPlus; }
{minusop}       { return Tokentype::OpArtMinus; }
{multop}        { return Tokentype::OpArtMult; }
{divop}         { return Tokentype::OpArtDiv; }
{modop}         { return Tokentype::OpArtModulus; }
{assignmentop}  { return Tokentype::OpAssign; }

    /** match types **/
{int}           { return Tokentype::IntValue; }
{real}          { return Tokentype::RealValue; }
{bool}          { return Tokentype::BoolValue; }

    /** identifiers **/
{identifier}    { return Tokentype::Identifier; }

<<EOF>>         { return Tokentype::EOI; }

    /** match any other token as unknown **/
.               { return Tokentype::ErrUnknown; }
%%
 // No need to add any code here.