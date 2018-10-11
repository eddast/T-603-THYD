////////////////////////////////////////////////////////////////////////////////////

%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define parser_class_name {parser_decaf}

%define api.token.constructor
%define api.value.type variant

%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires
{
#include <string>
#include "ast.h"
class Parser;
}

%parse-param { Parser& driver }
%locations
%code
{
#include "parser.h"
}

%token EOI 0

%token kwClass
%token kwStatic
%token kwVoid
%token kwInt
%token kwReal
%token kwBool
%token kwReturn
%token kwBreak
%token kwContinue
%token kwIf
%token kwElse
%token kwFor

%token ptLBrace
%token ptRBrace
%token ptLBracket
%token ptRBracket
%token ptComma
%token ptSemicolon
%token ptLParen
%token ptRParen

%token OpAssign
%token OpArtPlus
%token OpArtMinus
%token OpArtMult
%token OpArtDiv
%token OpArtModulus
%token OpArtInc
%token OpArtDec
%token OpRelEQ
%token OpRelNEQ
%token OpRelLT
%token OpRelLTE
%token OpRelGT
%token OpRelGTE
%token OpLogAnd
%token OpLogOr
%token OpLogNot

%token <std::string> Identifier
%token <std::string> IntValue
%token <std::string> RealValue
%token <std::string> BoolValue
%token <std::string> ErrUnknown

/* Types of variable grammar */
/*
%type <std::list<VariableDeclarationNode*>*> var_dec
%type <ValueType> type
%type <std::list<VariableNode*>*> var_list
%type <VariableNode*> variable
*/

/* Types of expression grammar */
%type <ExprNode*> expr valueExpr varExpr
%type <std::list<ExprNode*>*> expr_list more_expr

/* Operator precedence and associativity */
%left OpLogOr
%left OpLogAnd
%left OpRelEQ OpRelNEQ
%nonassoc OpRelGT OpRelGTE OpRelLT OpRelLTE
%left OpArtPlus OpArtMinus
%left OpArtMult OpArtDiv OpArtModulus
%right OpLogNot

%%

////////////////////////////////////////////////////////////////////////////////////
/*
program     : kwClass Identifier ptLBrace
             var_dec ptRBrace                               { driver.set_AST( new ProgramNode( $2, $4, nullptr ) ); }

var_dec     : var_dec type var_list ptSemicolon             { $$ = $1; $$->push_back( new VariableDeclarationNode($2,$3) ); }
            |                                               { $$ = new std::list<VariableDeclarationNode*>(); }

type        : kwInt                                         { $$ = ValueType::IntVal; }
            | kwReal                                        { $$ = ValueType::RealVal; }
            | kwBool                                        { $$ = ValueType::BoolVal; }

var_list    : variable                                      { $$ = new std::list<VariableNode*>(); $$->push_back( $1 ); }
            | var_list ptComma variable                     { $$ = $1; $$->push_back( $3 ); }

variable    : Identifier                                    { $$ = new VariableNode($1); }
            | Identifier ptLBracket IntValue ptRBracket     { $$ = new VariableNode($1,std::stoi($3)); }
*/
program: expr
            { driver.set_AST( $1 ); } /* TEMP */

expr_list   : expr more_expr                                { $$ = $2; $$->push_front( $1 ); }
            |                                               { $$ = new std::list<ExprNode*>(); }

more_expr   : ptComma expr more_expr                        { $$ = $3; $$->push_front( $2 ); }
            |                                               { $$ = new std::list<ExprNode*>(); }

expr        :   expr OpLogOr expr                           { $$ = new OrExprNode( $1, $3 ); }
            |   expr OpLogAnd expr                          { $$ = new AndExprNode( $1, $3 ); }
            |   expr OpRelEQ expr                           { $$ = new EqExprNode( $1, $3 ); }
            |   expr OpRelNEQ expr                          { $$ = new NeqExprNode( $1, $3 ); }
            |   expr OpRelLT expr                           { $$ = new LtExprNode( $1, $3 ); }
            |   expr OpRelLTE expr                          { $$ = new LteExprNode( $1, $3 ); }
            |   expr OpRelGT expr                           { $$ = new GtExprNode( $1, $3 ); }
            |   expr OpRelGTE expr                          { $$ = new GteExprNode( $1, $3 ); }
            |   expr OpArtPlus expr                         { $$ = new PlusExprNode( $1, $3 ); }
            |   expr OpArtMinus expr                        { $$ = new MinusExprNode( $1, $3 ); }
            |   expr OpArtMult expr                         { $$ = new MultiplyExprNode( $1, $3 ); }
            |   expr OpArtDiv expr                          { $$ = new DivideExprNode( $1, $3 ); }
            |   expr OpArtModulus expr                      { $$ = new ModulusExprNode( $1, $3 ); }
            |   OpArtPlus expr                                  %prec OpLogNot
                                                            { $$ = new PlusExprNode( $2 ); }
            |   OpArtMinus expr                                 %prec OpLogNot
                                                            { $$ = new MinusExprNode( $2 ); }
            |   OpLogNot expr                               { $$ = new NotExprNode( $2 ); }
            |   varExpr                                     { $$ = $1; }
            |   Identifier ptLParen expr_list ptRParen      { $$ = new MethodCallExprStmNode( $1, $3 ); }
            |   valueExpr                                   { $$ = $1; }
            |   ptLParen expr ptRParen                      { $$ = $2; }

varExpr     :   Identifier                                  { $$ = new VariableExprNode( $1 ); }
            |   Identifier ptLBracket IntValue ptRBracket   { $$ = new VariableExprNode( $1 ); }

valueExpr   :   IntValue                                    { $$ = new ValueExprNode( $1 ); }
            |   RealValue                                   { $$ = new ValueExprNode( $1 ); }
            |   BoolValue                                   { $$ = new ValueExprNode( $1 ); }
%%

////////////////////////////////////////////////////////////////////////////////////


void yy::parser_decaf::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
