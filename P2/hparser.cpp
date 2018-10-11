
#include "hparser.h"

using namespace std;

/**
 * Begins parsing of program file
 * @return 0 if no error occurs
 */
int HParser::parse()
{
    set_AST( program() );
    return 0;
}

/**
 * Matches a decaf program
 * program ::= class id { variable_declarations method_declarations }
 * @return AST Node for program
 */
ProgramNode*
HParser::program() {
    match( decaf::token_type::kwClass );
    string name = token_.lexeme;
    match( decaf::token_type::Identifier );
    match( decaf::token_type::ptLBrace );
    auto list_vdn = variable_declarations();
    auto list_mdn = method_declarations();
    match( decaf::token_type::ptRBrace );
    match( decaf::token_type::EOI );
    return new ProgramNode(name, list_vdn, list_mdn);
}

/**
 * Matches variable declaration list within program
 * variable_declarations ::= type variable_list; variable_declarations | Ɛ
 * @return AST node list of variable declarations matched
 */
list<VariableDeclarationNode*>*
HParser::variable_declarations()
{
    auto list_vdn = new list<VariableDeclarationNode*>();
    while ( token_.type == decaf::token_type::kwInt ||
            token_.type == decaf::token_type::kwReal ||
            token_.type == decaf::token_type::kwBool ) {
        ValueType type = this->type();
        auto list_v = variable_list();
        list_vdn->push_back( new VariableDeclarationNode( type, list_v ) );
    }
    return list_vdn;
}

/**
 * Matches variable type within program
 * type ::= int | real | bool
 * @return AST value node corresponding to type
 */
ValueType HParser::type()
{
    ValueType valuetype = ValueType::VoidVal;
    if ( token_.type == decaf::token_type::kwInt ) {
        match( decaf::token_type::kwInt );
        valuetype = ValueType::IntVal;
    }
    else if ( token_.type == decaf::token_type::kwReal ) {
        match( decaf::token_type::kwReal );
        valuetype = ValueType::RealVal;
    }
    else if ( token_.type == decaf::token_type::kwBool ) {
        match( decaf::token_type::kwBool );
        valuetype = ValueType::BoolVal;
    }
    else {
       error( decaf::token_type::kwInt );
    }
    return valuetype;
}


/**
 * Matches variable declaration list within program
 * variable_declarations ::= type variable_list; variable_declarations | Ɛ
 * @return list of AST variable nodes matched
 */
list<VariableNode*>*
HParser::variable_list()
{
    auto list_v = new list<VariableNode*>();
    list_v->push_back( variable() );
    while ( token_.type == decaf::token_type::ptComma ) {
        match( decaf::token_type::ptComma );
        list_v->push_back( variable() );
    }
    match( decaf::token_type::ptSemicolon );
    return list_v;
}


/**
 * Matches variable within program
 * variable ::= id | id[int_value]
 * @return AST variable node matched
 */
VariableNode*
HParser::variable()
{
    string id = token_.lexeme;
    int dim = 0;
    match( decaf::token_type::Identifier );
    if ( token_.type == decaf::token_type::ptLBracket ) {
        match( decaf::token_type::ptLBracket );
        if ( token_.type == decaf::token_type::IntValue) {
            dim = stoi(token_.lexeme);
        }
        match( decaf::token_type::IntValue );
        match( decaf::token_type::ptRBracket );
    }
    return new VariableNode( id, dim );
}

/**
 * Matches variable expression within program
 * @return AST variable node matched
 */
VariableExprNode*
HParser::variable_expr()
{
    string id = token_.lexeme;
    match( decaf::token_type::Identifier );
    if ( token_.type == decaf::token_type::ptLBracket ) {
        match( decaf::token_type::ptLBracket );
        match( decaf::token_type::IntValue );
        match( decaf::token_type::ptRBracket );
    }
    return new VariableExprNode( id );
}

/**
 * Matches variable assignment expression within program
 * @return AST variable assignment node
 */
AssignStmNode*
HParser::variable_assignment_expr()
{
    string lhs = token_.lexeme;
    match( decaf::token_type::Identifier );
    if ( token_.type == decaf::token_type::ptLBracket ) {
        match( decaf::token_type::ptLBracket );
        match( decaf::token_type::IntValue );
        match( decaf::token_type::ptRBracket );
    }
    match( decaf::token_type::OpAssign );
    auto rhs = expr();
    match( decaf::token_type::ptSemicolon );
    return new AssignStmNode( new VariableExprNode( lhs ), rhs );
}

/**
 * Matches list method declarations within program
 * method_declarations ::= method_declaration method_declarations | method_declaration
 * @return List of method nodes for AST in declaration list with relevant values
 */
list<MethodNode*>*
HParser::method_declarations()
{
    auto list_v = new list<MethodNode*>();
    list_v->push_back( method_declaration() );
    while ( token_.type == decaf::token_type::kwStatic ) {
        list_v->push_back( method_declaration() );
    }
    return list_v;
}

/**
 * Matches single method declaration within program
 * method_declaration ::= static method_return_type id(parameters){ variable_declarations statement_list}
 * @return Method node for AST with relevant values
 */
MethodNode*
HParser::method_declaration()
{
    match ( decaf::token_type::kwStatic );
    ValueType return_type = method_return_type();
    string id = token_.lexeme;
    match( decaf::token_type::Identifier );
    match( decaf::token_type::ptLParen );
    auto list_p = parameters();
    match( decaf::token_type::ptRParen );
    match( decaf::token_type::ptLBrace );
    list<VariableDeclarationNode*>* vars_decl = variable_declarations();
    auto list_stm = statement_list();
    match( decaf::token_type::ptRBrace );

    return new MethodNode( return_type, id, list_p, vars_decl, list_stm );
}

/**
 * Matches method return types within program
 * method_return_type ::= type | void
 * @return value type for the method return type
 */
ValueType HParser::method_return_type()
{
    if( token_.type == decaf::token_type::kwVoid ) {
        match( decaf::token_type::kwVoid );
        return ValueType::VoidVal;
    }
    return type();
}

/**
 * Matches optional parameter list within program
 * parameters ::= parameter_list | Ɛ
 * @return Parameter node with relevant values for AST
 */
list<ParameterNode*>*
HParser::parameters()
{
    auto list_p = new list<ParameterNode*>();
    if (token_.type == decaf::token_type::kwInt ||
        token_.type == decaf::token_type::kwReal ||
        token_.type == decaf::token_type::kwBool) {
        list_p = parameter_list();
    }
    return list_p;
}

/**
 * Matches a parameter list within program
 * parameter_list ::= type variable | type variable , parameter_list
 * @return Parameter node with relevant values for AST
 */
list<ParameterNode*>*
HParser::parameter_list()
{
    auto list_p = new list<ParameterNode*>();
    ValueType type = this->type();
    auto node_ve = this->variable_expr();
    list_p->push_back( new ParameterNode(type, node_ve) );
    while ( token_.type == decaf::token_type::ptComma ) {
        type = this->type();
        node_ve = this->variable_expr();
        list_p->push_back( new ParameterNode(type, node_ve) );
    }

    return list_p;
}

IncrDecrStmNode*
HParser::inc_dec_statement()
{
    auto node_var = variable_expr();
    if( token_.type == decaf::token_type::OpArtInc ) {
        match( decaf::token_type::OpArtInc );
        return new IncrStmNode( node_var );
    }
    else if( token_.type == decaf::token_type::OpArtDec ) {
        match( decaf::token_type::OpArtDec );
        return new DecrStmNode(node_var);
    }
    else {
        error( decaf::token_type::OpArtInc );
        return nullptr;
    }
}

/**
 * Matches optional statements within program
 * statement_list ::= statement statement_list | Ɛ
 * @return TODO
 */
list<StmNode*>*
HParser::statement_list()
{
    auto list_stm = new list<StmNode*>();
    while ( token_.type == decaf::token_type::kwIf ||
            token_.type == decaf::token_type::kwFor ||
            token_.type == decaf::token_type::kwReturn ||
            token_.type == decaf::token_type::kwBreak ||
            token_.type == decaf::token_type::kwContinue ||
            token_.type == decaf::token_type::ptLBrace ||
            token_.type == decaf::token_type::Identifier ) {
        auto stmt = statement();
        list_stm->push_back(stmt);
    }
    return list_stm;
}

/**
 * Matches a single statement within program
 * statement ::=    if(expr) statement_block optional_else
 *                  |   for(variable=expr; expr; variable op_incr_decr) statement_block
 *                  |   return optional_expr;
 *                  |   break;
 *                  |   continue;
 *                  |   statement_block
 *                  |   id_start_stm
 * @return AST statement node with all relevant parameters
 */
 StmNode*
 HParser::statement()
{
    // match if statement
    if( token_.type == decaf::token_type::kwIf ) {
        match( decaf::token_type::kwIf );
        match( decaf::token_type::ptLParen );
        auto node_ex = expr();
        match( decaf::token_type::ptRParen );
        auto node_stmb = statement_block();
        auto node_else = optional_else();
        return new IfStmNode( node_ex, node_stmb, node_else );
    }
    // match for loop
    else if( token_.type == decaf::token_type::kwFor ) {
        match( decaf::token_type::kwFor );
        match( decaf::token_type::ptLParen );
        auto node_asstm = variable_assignment_expr();
        auto node_ex = expr();
        match( decaf::token_type::ptSemicolon );
        auto node_inc_dec = inc_dec_statement();
        match( decaf::token_type::ptRParen );
        auto node_stmb = statement_block();
        return new ForStmNode( node_asstm, node_ex, node_inc_dec, node_stmb );
    }
    // match return statement
    else if( token_.type == decaf::token_type::kwReturn ) {
        match( decaf::token_type::kwReturn );
        if( token_.type == decaf::token_type::ptSemicolon ) {
            match( decaf::token_type::ptSemicolon );
            return new ReturnStmNode( );
        }
        // TODO VIRKAR EKKI
        auto node_e = expr();
        match( decaf::token_type::ptSemicolon );
        return new ReturnStmNode( node_e );
    }
    // match break statement
    else if( token_.type == decaf::token_type::kwBreak ) {
        match( decaf::token_type::kwBreak );
        match( decaf::token_type::ptSemicolon );
        return new BreakStmNode();
    }
    // match continue statement
    else if( token_.type == decaf::token_type::kwContinue ) {
        match( decaf::token_type::kwContinue );
        match( decaf::token_type::ptSemicolon );
        return new ContinueStmNode();
    }
    // match statement block
    else if( token_.type == decaf::token_type::ptLBrace ) {
        match( decaf::token_type::ptLBrace );
        auto list_stms = statement_list();
        match( decaf::token_type::ptRBrace );
        return new BlockStmNode( list_stms );
    }
    // match id start statement
    else if( token_.type == decaf::token_type::Identifier ) {
        return id_start_stm();
    }
    error( decaf::token_type::kwIf );
    return nullptr;
}

/**
 * Matches statement starting with identifier
 * id_start_stm ::= id(expr_list);
 *                  |   variable op_incr_decr;
 *                  |   variable = expr;
 * @return AST statement node with relevant parameters
 */
 StmNode*
 HParser::id_start_stm()
{
    string name = token_.lexeme;
    match( decaf::token_type::Identifier );

    // id (expression list)
    if( token_.type == decaf::token_type::ptLParen ) {
        match( decaf::token_type::ptLParen );
        auto list_ex = expr_list();
        match( decaf::token_type::ptRParen );
        match( decaf::token_type::ptSemicolon );
        return new MethodCallExprStmNode( name, list_ex );
    }
    // variable
    if ( token_.type == decaf::token_type::ptLBracket ) {
        match( decaf::token_type::ptLBracket );
        match( decaf::token_type::IntValue );
        match( decaf::token_type::ptRBracket );
    }
    // variable op_incr_dec
    if( token_.type == decaf::token_type::OpArtInc ||
        token_.type == decaf::token_type::OpArtDec ) {

        if( token_.type == decaf::token_type::OpArtInc ) {
            match( decaf::token_type::OpArtInc );
            match( decaf::token_type::ptSemicolon );
            return new IncrStmNode( new VariableExprNode( name ) );
        }
        else {
            match( decaf::token_type::OpArtDec );
            match( decaf::token_type::ptSemicolon );
            return new DecrStmNode( new VariableExprNode( name ) );
        }
    }
    // variable = expr;
    else {
        match( decaf::token_type::OpAssign );
        auto rhs = expr();
        match( decaf::token_type::ptSemicolon );
        return new AssignStmNode( new VariableExprNode( name ), rhs );
    }
}

/**
 * Matches a statement block within program
 * statement_block ::= { statement_list }
 * @return AST node for block statement with all it's statements
 */
BlockStmNode*
HParser::statement_block()
{
    match( decaf::token_type::ptLBrace );
    auto list_stms = statement_list();
    match( decaf::token_type::ptRBrace );

    return new BlockStmNode( list_stms );
}

/**
 * Matches an optional else statement within program
 * optional_else ::= else statement_block | Ɛ
 * @return block statement AST node for statement or null pointer if none is matched
 */
BlockStmNode*
HParser::optional_else()
{
    if( token_.type == decaf::token_type::kwElse ) {
        match(decaf::token_type::kwElse);
        match( decaf::token_type::ptLBrace );
        auto list_stms = statement_list();
        match( decaf::token_type::ptRBrace );

        return new BlockStmNode( list_stms );
    }
    else {
        return nullptr;
    }
}

/**
 * Matches expression list within program
 * expr_list ::= expr more_expr | Ɛ
 * @return TODO
 */
list<ExprNode*>*
HParser::expr_list()
{
    list<ExprNode*>* list_ex = new list<ExprNode*>();
    // TODO HVAÐ BYRJAR EXPRESSION Á ??? VANTAR OPTIONAL EXPRESSION
    auto node_ex = expr();
    list_ex->push_back(node_ex);
    list_ex = more_expr(list_ex);

    return list_ex;
}

/**
 * Matches extended expression list within program
 * more_expr ::= , expr more_expr | Ɛ
 * @return AST expression nodes with relevant values
 */
list<ExprNode*>*
HParser::more_expr( list<ExprNode*>* &list_ex )
{
    while( token_.type == decaf::token_type::ptComma ) {
        match( decaf::token_type::ptComma );
        auto node_ex = expr();
        list_ex->push_back(node_ex);
    }

    return list_ex;
}

/**
 * Matches a single expression within program
 * expr ::= expr_and expr'
 * @return Expression node with all relevant expressions
 */
ExprNode*
HParser::expr( ) { return expr2( expr_and() ); }

/**
 * Matches an optional left-hand side or-expression within program
 * expr' ::= || expr_and expr' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpLogOr ) {
        match( decaf::token_type::OpLogOr );
        auto rhs = expr();
        return new OrExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right-hand side expression valid to an and-expression within program
 * expr_and ::= expr_eq expr_and'
 * @return TODO
 */
ExprNode*
HParser::expr_and( ) { return expr_and2( expr_eq() ); }

/**
 * Matches an optional left-hand side and-expression within program
 * expr_and' ::= && expr_eq expr_and' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr_and2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpLogAnd ) {
        match( decaf::token_type::OpLogAnd );
        auto rhs = expr_and();
        return new AndExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right-hand side expression valid to an equality-expression within program
 * expr_eq ::= expr_rel expr_eq'
 * @return TODO
 */
ExprNode*
HParser::expr_eq( ) { return expr_eq2( expr_rel() ); }

/**
 * Matches an optional left-hand side and-expression within program
 * expr_eq' ::= op_eq expr_rel expr_eq' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr_eq2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpRelEQ ) {
        match( decaf::token_type::OpRelEQ );
        auto rhs = expr_eq();
        return new EqExprNode( lhs, rhs );
    }
    else if ( token_.type == decaf::token_type::OpRelNEQ ) {
        match( decaf::token_type::OpRelNEQ );
        auto rhs = expr_eq();
        return new NeqExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right-hand side expression valid to an relational-expression within program
 * expr_rel ::= expr_add expr_rel'
 * @return TODO
 */
ExprNode*
HParser::expr_rel( ) { return expr_rel2( expr_add() ); }

/**
 * Matches an optional left-hand side relational-expression within program
 * expr_rel' ::= op_rel expr_add expr_rel' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr_rel2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpRelGT ) {
        match( decaf::token_type::OpRelGT );
        auto rhs = expr_rel();
        return new GtExprNode( lhs, rhs );
    }
    else if ( token_.type == decaf::token_type::OpRelGTE ) {
        match( decaf::token_type::OpRelGTE );
        auto rhs = expr_rel();
        return new GteExprNode( lhs, rhs );
    }
    else if ( token_.type == decaf::token_type::OpRelLT ) {
        match( decaf::token_type::OpRelLT );
        auto rhs = expr_rel();
        return new LtExprNode( lhs, rhs );
    }
    else if ( token_.type == decaf::token_type::OpRelLTE ) {
        match( decaf::token_type::OpRelLTE );
        auto rhs = expr_rel();
        return new LteExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right-hand side expression valid to an addition-expression within program
 * expr_add ::= expr_mult expr_add'
 * @return TODO
 */
ExprNode*
HParser::expr_add( )  {  return expr_add2( expr_mult() );  }

/**
 * Matches an optional left-hand side addition-expression within program
 * expr_add' ::= op_add expr_mult expr_add' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr_add2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpArtPlus ) {
        match( decaf::token_type::OpArtPlus );
        auto rhs = expr_add();
        return new PlusExprNode( lhs, rhs );
    }
    else if (token_.type == decaf::token_type::OpArtMinus ) {
        match( decaf::token_type::OpArtMinus );
        auto rhs = expr_add();
        return new MinusExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right-hand side expression valid to an multiply-expression within program
 * expr_mult ::= expr_unary expr_mult'
 * @return TODO
 */
ExprNode*
HParser::expr_mult( )  {  return expr_mult2( expr_unary() ); }

/**
 * Matches an optional left-hand side multiply-expression within program
 * expr_mult' ::= op_mult expr_unary expr_mult' | Ɛ
 * @return TODO
 */
ExprNode*
HParser::expr_mult2( ExprNode* lhs )
{
    if ( token_.type == decaf::token_type::OpArtMult ) {
        match( decaf::token_type::OpArtMult );
        auto rhs = expr_mult();
        return new MultiplyExprNode( lhs, rhs );
    }
    else if (token_.type == decaf::token_type::OpArtDiv ) {
        match( decaf::token_type::OpArtDiv );
        auto rhs = expr_mult();
        return new DivideExprNode( lhs, rhs );
    }
    else if (token_.type == decaf::token_type::OpArtModulus ) {
        match( decaf::token_type::OpArtModulus );
        auto rhs = expr_mult();
        return new ModulusExprNode( lhs, rhs );
    }

    // TODO RETURN WHAT EF EKKERT PASSAR I.E. ÞEGAR Ɛ?????
    return nullptr;
}

/**
 * Matches right associative unary-expression within program or a factor value
 * expr_unary ::= op_unary expr_unary | factor
 * @return Expression Node: Unary expression node or nested expression node
 */
ExprNode*
HParser::expr_unary()
{
    // factor
    if ( token_.type == decaf::token_type::ptLParen ||
         token_.type == decaf::token_type::Identifier ||
         token_.type == decaf::token_type::IntValue ||
         token_.type == decaf::token_type::BoolValue ||
         token_.type == decaf::token_type::RealValue) {
        return factor();
    }
    // if not factor, we have unary expression
    else {
        if ( token_.type == decaf::token_type::OpArtPlus ) {
            match ( decaf::token_type::OpArtPlus );
            auto rhs = expr_unary();
            return new PlusExprNode ( rhs );
        }
        else if (token_.type == decaf::token_type::OpArtMinus) {
            match ( decaf::token_type::OpArtMinus );
            auto rhs = expr_unary();
            return new MinusExprNode ( rhs );
        }
        else if (token_.type == decaf::token_type::OpLogNot ) {
            match ( decaf::token_type::OpLogNot );
            auto rhs = expr_unary();
            return new NotExprNode ( rhs );
        }
        error( decaf::token_type::OpArtPlus );
        return nullptr;
    }
}

/**
 * Matches factor value within program
 * factor ::= value | (expr) | variable | id(expr_list)
 * @return AST expression node for factor value or nested expression
 */
ExprNode*
HParser::factor()
{
    if ( token_.type == decaf::token_type::ptLParen ) {
        match( decaf::token_type::ptLParen );
        ExprNode* node_ex = expr();
        match( decaf::token_type::ptRParen );
        return node_ex;
    }
    else if( token_.type == decaf::token_type::Identifier ) {
        string id = token_.lexeme;
        match( decaf::token_type::Identifier );
        if( token_.type == decaf::token_type::ptLParen ) {
            match( decaf::token_type::ptLParen );
            auto list_ex = expr_list();
            match( decaf::token_type::ptRParen );
            return new MethodCallExprStmNode( id, list_ex );
        }
        else {
            if ( token_.type == decaf::token_type::ptLBracket ) {
                match( decaf::token_type::ptLBracket );
                match( decaf::token_type::IntValue );
                match( decaf::token_type::ptRBracket );
            }
            return new VariableExprNode( id );
        }
    }
    else if ( token_.type == decaf::token_type::IntValue ||
              token_.type == decaf::token_type::BoolValue ||
              token_.type == decaf::token_type::RealValue) {
        return value();
    }
    error( decaf::token_type::ptLParen );
    return nullptr;
}

/**
 * Matches value within program
 * value ::= int_value | real_value | bool_value
 */
ExprNode*
HParser::value()
{
    if ( token_.type == decaf::token_type::IntValue ||
         token_.type == decaf::token_type::BoolValue ||
         token_.type == decaf::token_type::RealValue) {
        string val = token_.lexeme;
        match( token_.type );
        return new ValueExprNode( val );
    }
    error( decaf::token_type::IntValue );
    return nullptr;
}
