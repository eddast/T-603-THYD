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


/************************
 *  TOKEN DECLARATIONS  *
 ************************/

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


/*************************
 *  TYPE DECLARATIONS    *
 *************************/

/* Types of variable grammar */
%type <std::list<VariableDeclarationNode*>*> variable_decs
%type <ValueType> type method_ret_type
%type <std::list<VariableNode*>*> var_list
%type <VariableNode*> variable

/* Types of method grammar */
%type <std::list<MethodNode*>*> method_decs
%type <MethodNode*> method_dec

/* Types of parameter grammar */
%type <std::list<ParameterNode*>*> parameters parameter_list

/* Types of statement grammar */
%type <std::list<StmNode*>*> statement_list
%type <StmNode*> statement
%type <AssignStmNode*> variable_assign
%type <IncrDecrStmNode*> incr_decr_var
%type <BlockStmNode*> statement_block optional_else

/* Types of expression grammar */
%type <ExprNode*> expr value_expr
%type <std::list<ExprNode*>*> expr_list more_expr
%type <VariableExprNode*> variable_expr


/****************************************
 *  OPERATOR PRECEDENCE/ASSOCIATIVITY   *
 ****************************************/

%left OpLogOr
%left OpLogAnd
%left OpRelEQ OpRelNEQ
%nonassoc OpRelGT OpRelGTE OpRelLT OpRelLTE
%left OpArtPlus OpArtMinus
%left OpArtMult OpArtDiv OpArtModulus
%right OpLogNot

%%

////////////////////////////////////////////////////////////////////////////////////


/********************************************
 *  BISON AUGMENTED GRAMMAR DECLARATIONS    *
 ********************************************/

program         :   kwClass Identifier ptLBrace
                    variable_decs method_decs ptRBrace          { driver.set_AST( new ProgramNode( $2, $4, $5 ) ); }

variable_decs   :   variable_decs type var_list ptSemicolon     { $$ = $1; $$->push_back( new VariableDeclarationNode($2,$3) ); }
                |                                               { $$ = new std::list<VariableDeclarationNode*>(); }

type            :   kwInt                                       { $$ = ValueType::IntVal; }
                |   kwReal                                      { $$ = ValueType::RealVal; }
                |   kwBool                                      { $$ = ValueType::BoolVal; }

var_list        :   variable                                    { $$ = new std::list<VariableNode*>(); $$->push_back( $1 ); }
                |   var_list ptComma variable                   { $$ = $1; $$->push_back( $3 ); }

variable        :   Identifier                                  { $$ = new VariableNode($1); }
                |   Identifier ptLBracket IntValue ptRBracket   { $$ = new VariableNode($1,std::stoi($3)); }

variable_assign :   variable_expr OpAssign expr                 { $$ = new AssignStmNode( $1, $3 ); }

method_decs     :   method_decs method_dec                      { $$ = $1; $$->push_front( $2 ); }
                |   method_dec                                  { $$ = new std::list<MethodNode*>(); $$->push_back($1); }

method_dec      :   kwStatic method_ret_type Identifier
                    ptLParen parameters ptRParen
                    ptLBrace variable_decs statement_list
                    ptRBrace                                    { $$ = new MethodNode( $2, $3, $5, $8, $9 ); }

method_ret_type :   type                                        { $$ = $1; }
                |   kwVoid                                      { $$ = ValueType::VoidVal; }

parameters      :   parameter_list                              { $$ = $1; }
                |                                               { $$ = new std::list<ParameterNode*>(); }

parameter_list  :   type variable_expr                          { $$ = new std::list<ParameterNode*>(); $$->push_back( new ParameterNode( $1, $2 ) ); }
                |   parameter_list ptComma type variable_expr   { $$ = $1; $$->push_back( new ParameterNode( $3, $4 ) ); }

statement_list  :   statement_list statement                    { $$ = $1; $$->push_back( $2 ); }
                |                                               { $$ = new std::list<StmNode*>(); }

statement       :   variable_assign ptSemicolon                 { $$ = $1; }
                /*|   Identifier ptLParen expr_list ptRParen      { $$ = MethodCallExprStmNode( $1, $3 ); }*/
                |   kwIf ptLParen expr ptRParen
                    statement_block optional_else               { $$ = new IfStmNode( $3, $5, $6 ); }
                /*|   kwFor ptLParen
                    variable_assign ptSemicolon
                    expr ptSemicolon
                    incr_decr_var
                    ptRParen
                    statement_block                             { $$ = ForStmNode( $3, $5, $7, $9 ); }*/
                |   kwReturn ptSemicolon                        { $$ = new ReturnStmNode( ); }
                |   kwReturn expr ptSemicolon                   { $$ = new ReturnStmNode( $2 ); }
                |   kwBreak ptSemicolon                         { $$ = new BreakStmNode( ); }
                |   kwContinue ptSemicolon                      { $$ = new ContinueStmNode( ); }
                |   incr_decr_var ptSemicolon                   { $$ = $1; }
                |   statement_block                             { $$ = $1; }

statement_block :   ptLBrace statement_list ptRBrace            { $$ = new BlockStmNode( $2 ); }

incr_decr_var   :   variable_expr OpArtInc                      { $$ = new IncrStmNode( $1 ); }
                |   variable_expr OpArtDec                      { $$ = new DecrStmNode( $1 ); }

optional_else   :   kwElse statement_block                      { $$ = $2; }
                |                                               { $$ = nullptr; }

expr_list       :   expr more_expr                              { $$ = $2; $$->push_front( $1 ); }
                |                                               { $$ = new std::list<ExprNode*>(); }

more_expr       :   ptComma expr more_expr                      { $$ = $3; $$->push_front( $2 ); }
                |                                               { $$ = new std::list<ExprNode*>(); }

expr            :   expr OpLogOr expr                           { $$ = new OrExprNode( $1, $3 ); }
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
                |   variable_expr                               { $$ = $1; }
                |   Identifier ptLParen expr_list ptRParen      { $$ = new MethodCallExprStmNode( $1, $3 ); }
                |   value_expr                                  { $$ = $1; }
                |   ptLParen expr ptRParen                      { $$ = $2; }

variable_expr   :   Identifier                                  { $$ = new VariableExprNode( $1 ); }
                |   Identifier ptLBracket IntValue ptRBracket   { $$ = new VariableExprNode( $1 ); }

value_expr      :   IntValue                                    { $$ = new ValueExprNode( $1 ); }
                |   RealValue                                   { $$ = new ValueExprNode( $1 ); }
                |   BoolValue                                   { $$ = new ValueExprNode( $1 ); }
%%

////////////////////////////////////////////////////////////////////////////////////


void yy::parser_decaf::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
