#ifndef DECAFPARSER_AST_H
#define DECAFPARSER_AST_H

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include "symbol_table.h"
#include "tac.h"


/////////////////////////////////////////////////////////////////////////////////

struct Data {

    Data( SymbolTable& st )
            : sym_table(st), variable_no(0), label_no(0), expr_return_type(ValueType::VoidVal) {}

    SymbolTable& sym_table;         // Reference to the symbol-table; do not delete.

    int variable_no;                // Counters for increasing the numbers of
    int label_no;                   // variables and labels.

    std::string method_name;        // Method name, needed for return.
    std::stack<int> for_label_no;   // The label_no of enclosing for loops,
                                    // Needed for continue/break statements.

    std::string expr_return_var;    // Variable used to store expr value.
    ValueType   expr_return_type;   // Type of expression evaluated.

};

/**
 * Output warning message
 * @param message to output
 */
inline void warning_msg( std::string message )
{
    std::cout << "WARNING: " << message << std::endl;
}

/**
 * Outputs error message
 * @param message to output
 */
inline void error_msg( std::string message )
{
    std::cout << "ERROR: " << message << std::endl;
    throw;
}

/**
 * Adds entry to symbol table
 * @param st the symbol table to add entry to
 * @param entry_type type of entry (variable, value etc.)
 * @param scope scope e.g. the method name symbol table entry belongs to
 * @param name identifier name for new entry
 * @param value_type type of new entry
 * @param signature
 */
inline void add_to_symbol_table( SymbolTable& st, EntryType entry_type, std::string scope,
                                 std::string name, ValueType value_type, std::string signature )
{
    SymbolTable::Entry *entry = st.lookup( scope, name );
    if ( entry == nullptr ) {
        SymbolTable::Entry entry;
        entry.name = name;
        entry.scope = scope;
        entry.entry_type = entry_type;
        entry.value_type = value_type;
        entry.signature = signature;
        st.add( entry );
    }
    else {
        error_msg("Identifier '" + name + "' already declared in scope.");
    }
}

/////////////////////////////////////////////////////////////////////////////////


class Node {
public:
    virtual const std::string str( ) const = 0;
    virtual void icg( Data& data, TAC& tac ) const = 0;
    virtual ~Node() = default;
};

inline std::string tostr( const Node* node ) {
    return (node == nullptr ? "(null)" : node->str() );
}


/////////////////////////////////////////////////////////////////////////////////

class ExprNode : public Node { };


class ValueExprNode : public ExprNode
{
public:
    explicit ValueExprNode( const std::string value ) : value_(value) { }

    virtual void icg( Data& data, TAC& tac ) const override {
        data.expr_return_var = value_;
        data.expr_return_type =
                (std::all_of(value_.begin(), value_.end(), ::isdigit) ? ValueType::IntVal : ValueType::RealVal);
    }

    virtual const std::string str( ) const override {
        return std::string("(VAL ") + value_ + ')';
    }

protected:
    std::string value_;
};


class AndExprNode : public ExprNode
{
public:
    AndExprNode( ExprNode *lhs, ExprNode *rhs ) : lhs_(lhs), rhs_(rhs) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Extract name and return type from left-hand side expression
        lhs_->icg( data, tac );
        std::string var_lhs = data.expr_return_var;
        ValueType type_lhs = data.expr_return_type;

        // Extract name and return type from right-hand side expression
        rhs_->icg( data, tac );
        std::string var_rhs = data.expr_return_var;
        ValueType type_rhs = data.expr_return_type;

        // Create label for point in program where we'd go to if and-expression resolves to false
        // Create label for point in program immediately following the and-expression
        std::string lab_and_false = tac.label_name("and_false", data.label_no);
        std::string lab_and_end = tac.label_name("and_end", data.label_no);
        data.label_no++;

        // Create temporary variable for return value
        std::string var = tac.tmp_variable_name( data.variable_no++ );
        tac.append( TAC::InstrType::VAR, var );

        // If either expression evaluates to true,
        // Jump to code that assigns return statement to false
        tac.append( TAC::InstrType::EQ, var_lhs, "0", lab_and_false );
        tac.append( TAC::InstrType::EQ, var_rhs, "0", lab_and_false );

        // The section executed if both expression evaluate to true
        // Set up return value to evaluate to true
        // Then jump to end of and-expression
        tac.append( TAC::InstrType::ASSIGN, "1", var );
        tac.append( TAC::InstrType::GOTO, lab_and_end );

        // The section executed if either expression evaluates to false
        // Set up and-expression's return value to evaluate to false
        tac.label_next_instr( lab_and_false );
        tac.append( TAC::InstrType::ASSIGN, "0", var );
        tac.label_next_instr( lab_and_end );

        // Set up and configure return value
        data.expr_return_var = var;
        data.expr_return_type = ValueType::IntVal;

        // Warn user if right-hand side type resolves to a Real value
        // (Int and Bool values both considered OK when using not operator)
        if ( type_rhs == ValueType::RealVal ) {
            warning_msg("Type mismatch in logical ! operation (operand is not an integer/bool value)." );
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(&& ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }

protected:
    ExprNode *lhs_, *rhs_;
};


class OrExprNode : public ExprNode
{
public:
    OrExprNode( ExprNode *lhs, ExprNode *rhs ) : lhs_(lhs), rhs_(rhs) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Extract name and return type from left-hand side expression
        lhs_->icg( data, tac );
        std::string var_lhs = data.expr_return_var;
        ValueType type_lhs = data.expr_return_type;

        // Extract name and return type from right-hand side expression
        rhs_->icg( data, tac );
        std::string var_rhs = data.expr_return_var;
        ValueType type_rhs = data.expr_return_type;

        // Create label for point in program where we'd go to if or-expression resolves to true
        // Create label for point in program immediately following the or-expression
        std::string lab_or_true = tac.label_name("or_true", data.label_no);
        std::string lab_or_end = tac.label_name("or_end", data.label_no);
        data.label_no++;

        // Create temporary variable for return value
        std::string var = tac.tmp_variable_name( data.variable_no++ );
        tac.append( TAC::InstrType::VAR, var );

        // If either expression evaluates to true,
        // Jump to code that assigns return statement to true
        tac.append( TAC::InstrType::EQ, var_lhs, "1", lab_or_true );
        tac.append( TAC::InstrType::EQ, var_rhs, "1", lab_or_true );

        // The section executed if neither expression evaluates to true
        // Set up return value to evaluate to false
        // Then jump to end of or-expression
        tac.append( TAC::InstrType::ASSIGN, "0", var );
        tac.append( TAC::InstrType::GOTO, lab_or_end );

        // The section executed if either expression evaluates to true
        // Set up or-expression's return value to evaluate to true
        tac.label_next_instr( lab_or_true);
        tac.append( TAC::InstrType::ASSIGN, "1", var );
        tac.label_next_instr( lab_or_end );

        // Set up and configure return value
        data.expr_return_var = var;
        data.expr_return_type = ValueType::IntVal;

        // Warn user if right-hand side type resolves to a Real value
        // (Int and Bool values both considered OK when using not operator)
        if ( type_rhs == ValueType::RealVal ) {
            warning_msg("Type mismatch in logical ! operation (operand is not an integer/bool value)." );
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(|| ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }

protected:
    ExprNode *lhs_, *rhs_;
};


class NotExprNode : public ExprNode
{
public:
    NotExprNode( ExprNode *rhs ) : rhs_(rhs) {}

    virtual void icg( Data& data, TAC& tac ) const override {

        // Create label for point in program where we'd go to if not expression is true
        // Create label for point in program where we'd go to if not expression is false
        std::string lab_not_true = tac.label_name( "not_true", data.label_no );
        std::string lab_not_end = tac.label_name( "not_end", data.label_no );
        data.label_no++;

        // Create temporary variable for return value
        std::string var = tac.tmp_variable_name( data.variable_no++ );
        tac.append( TAC::InstrType::VAR, var );

        // Extract expression to the right of not operator
        rhs_->icg( data, tac );
        ValueType type_rhs = data.expr_return_type;

        // Set up expression to jump to code executed if expression not true if expression is not true
        tac.append( TAC::InstrType::NE, data.expr_return_var, "0", lab_not_true );

        // Set up return value to evaluate to true
        // Then jump to end of not expression
        tac.append( TAC::InstrType::ASSIGN, "1", var );
        tac.append( TAC::InstrType::GOTO, lab_not_end );

        // Section that is if not expression evaluates to false
        // Set up not equal expression to evaluate to false
        // Then label next instruction to end of not expression
        tac.label_next_instr( lab_not_true );
        tac.append( TAC::InstrType::ASSIGN, "0", var );
        tac.label_next_instr( lab_not_end );

        // Set up and configure return value
        data.expr_return_var = var;
        data.expr_return_type = ValueType::IntVal;

        // Warn user if right-hand side type resolves to a Real value
        // (Int and Bool values both considered OK when using not operator)
        if ( type_rhs == ValueType::RealVal ) {
            warning_msg("Type mismatch in logical ! operation (operand is not an integer/bool value)." );
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(! ") + tostr(rhs_) + ')';
    }

protected:
    ExprNode *rhs_;
};


class RelationalExprNode : public ExprNode {
public:

    RelationalExprNode( TAC::InstrType instr_type, ExprNode *lhs, ExprNode *rhs )
            : instr_type_(instr_type), lhs_(lhs), rhs_(rhs ) {}

    virtual void icg( Data& data, TAC& tac ) const override {

        // Extract name and return type from left-hand side e.g. the variable
        lhs_->icg( data, tac );
        std::string var_lhs = data.expr_return_var;
        ValueType type_lhs = data.expr_return_type;

        // Extract name and return type from right-hand side e.g. the expression
        rhs_->icg( data, tac );
        std::string var_rhs = data.expr_return_var;
        ValueType type_rhs = data.expr_return_type;

        // Create label for point in program where we'd go to if relational expression is true
        // Create label for point in program where we'd go to if relational expression is false
        std::string lab_rel_true = tac.label_name("rel_true", data.label_no);
        std::string lab_rel_end = tac.label_name("rel_end", data.label_no);
        data.label_no++;

        // Create and assign temporary variable to store return value in
        std::string var = tac.tmp_variable_name(data.variable_no++);
        tac.append( TAC::InstrType::VAR, var );

        // If expression evaluated is true, set up code to
        // jump to the code executed if expression is true
        tac.append( instr_type_, var_lhs, var_rhs, lab_rel_true );

        // The section executed if expression evaluates to false
        // Set up return value to evaluate to false
        // Then jump to end of relational expression
        tac.append( TAC::InstrType::ASSIGN, "0", var );
        tac.append( TAC::InstrType::GOTO, lab_rel_end );

        // The section executed if expression evaluates to true
        // Set up return value to evaluate to true
        tac.label_next_instr( lab_rel_true );
        tac.append( TAC::InstrType::ASSIGN, "1", var );
        tac.label_next_instr( lab_rel_end );

        // Set up and configure return value
        data.expr_return_var = var;
        data.expr_return_type = ValueType::IntVal;

        // Show warning on attempting comparison of values that have type mismatch
        // (Int and Bool comparison is considered OK)
        if ( (type_lhs == ValueType::RealVal && type_rhs != ValueType::RealVal) ||
             (type_lhs != ValueType::RealVal && type_rhs == ValueType::RealVal) ) {
            warning_msg("Type mismatch in operation " + tac.IName[instr_type_] + ".");
        }
    }

protected:
    TAC::InstrType instr_type_;
    ExprNode *lhs_, *rhs_;
};


class EqExprNode : public RelationalExprNode
{
public:
    EqExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::EQ, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(== ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class NeqExprNode : public RelationalExprNode
{
public:
    NeqExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::NE, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(!= ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class LtExprNode : public RelationalExprNode
{
public:
    LtExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::LT, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(< ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class LteExprNode : public RelationalExprNode
{
public:
    LteExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::LE, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(<= ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class GtExprNode : public RelationalExprNode
{
public:
    GtExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::GT, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(> ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class GteExprNode : public RelationalExprNode
{
public:
    GteExprNode( ExprNode *lhs, ExprNode *rhs )
            : RelationalExprNode( TAC::InstrType::GE, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(>= ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class ArithmeticExprNode: public ExprNode {
public:
    ArithmeticExprNode( TAC::InstrType instr_type, ExprNode *lhs, ExprNode *rhs )
            : instr_type_(instr_type), lhs_(lhs), rhs_(rhs ) {}

    virtual void icg( Data& data, TAC& tac ) const override
    {
        // Extract name and return type of left-hand side expression
        lhs_->icg( data, tac );
        std::string var_lhs = data.expr_return_var;
        ValueType type_lhs = data.expr_return_type;

        // Extract name and return type of right-hand side expression
        rhs_->icg( data, tac );
        std::string var_rhs = data.expr_return_var;
        ValueType type_rhs = data.expr_return_type;

        // Create and assign temporary variable to store return value in
        std::string var = tac.tmp_variable_name(data.variable_no++);
        tac.append( TAC::InstrType::VAR, var );

        // Add arithmetic instruction that stores result in temporary return value
        tac.append( instr_type_, var_lhs, var_rhs, var );

        // Set up and configure return value
        data.expr_return_var = var;
        data.expr_return_type = type_lhs;

        // Show warning on attempting arithmetic calculations of values that have type mismatch
        // (Int and Bool arithmetic is considered OK)
        if ( (type_lhs == ValueType::RealVal && type_rhs != ValueType::RealVal) ||
             (type_lhs != ValueType::RealVal && type_rhs == ValueType::RealVal) ) {
            warning_msg("Type mismatch in operation " + tac.IName[instr_type_] + ".");
        }
    }

protected:
    TAC::InstrType instr_type_;
    ExprNode *lhs_, *rhs_;
};


class MultiplyExprNode : public ArithmeticExprNode
{
public:
    MultiplyExprNode( ExprNode *lhs, ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::MULT, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(* ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};

class DivideExprNode : public ArithmeticExprNode
{
public:
    DivideExprNode( ExprNode *lhs, ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::DIVIDE, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(/ ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class ModulusExprNode : public ArithmeticExprNode
{
public:
    ModulusExprNode( ExprNode *lhs, ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::MOD, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        return std::string("(% ") + tostr(lhs_) + ' ' + tostr(rhs_) + ')';
    }
};


class PlusExprNode : public ArithmeticExprNode
{
public:
    PlusExprNode( ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::ADD, nullptr, rhs ) {}

    PlusExprNode( ExprNode *lhs, ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::ADD, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        std::string s = std::string("(+ ");
        if ( lhs_ != nullptr ) {
            s += tostr(lhs_) + ' ';
        }
        s += tostr(rhs_) + ')';
        return s;
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        if ( lhs_ == nullptr ) {
            rhs_->icg( data, tac );
        }
        else {
            ArithmeticExprNode::icg( data, tac );
        }
    }
};


class MinusExprNode : public ArithmeticExprNode
{
public:
    MinusExprNode( ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::SUB, nullptr, rhs ) {}
    MinusExprNode( ExprNode *lhs, ExprNode *rhs )
            : ArithmeticExprNode( TAC::InstrType::SUB, lhs, rhs ) {}

    virtual const std::string str( ) const override {
        std::string s = std::string("(- ");
        if ( lhs_ != nullptr ) {
            s += tostr(lhs_) + ' ';
        }
        s += tostr(rhs_) + ')';
        return s;
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // Provided.
        if ( lhs_ == nullptr ) {
            rhs_->icg( data, tac );
            std::string var = tac.tmp_variable_name(data.variable_no++);
            tac.append( TAC::InstrType::VAR, var );
            tac.append( TAC::InstrType::UMINUS, data.expr_return_var, var );
            data.expr_return_var = var;
        }
        else {
            ArithmeticExprNode::icg( data, tac );
        }
    }
};


class VariableNode : public ExprNode
{
public:

    explicit VariableNode( const std::string& id, int dim=0 ) : id_(id), dim_(dim) {
        if ( dim != 0 ) {
            error_msg( "Sorry, arrays are not supported in Part3 of the assignment!");
        }
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // Set up name of variable and initialize type to void before validation
        data.expr_return_var = id_;
        data.expr_return_type = ValueType::VoidVal;

        // Look up identifier for local scope using symbol table
        // Look up identifier for global scope using symbol table if not found there
        SymbolTable::Entry* entry = data.sym_table.lookup( data.method_name, id_ );
        if ( entry == nullptr && !data.method_name.empty() ) {
            entry = data.sym_table.lookup( "", id_ );
        }
        // Output error if identifier is referenced but not declared
        if ( entry == nullptr ) {
            error_msg("Undeclared identifier '" + id_ + "'.");
        }
        // Otherwise re-assign correct type to variable
        else {
            data.expr_return_type = entry->value_type;
        }
    }

    virtual const std::string str( ) const override {
        std::string str = std::string("(VAR ") + id_ ;
        if ( dim_ > 0 ) {
            str += '[' + std::to_string(dim_) + ']';
        }
        str += ')';
        return str;
    }

    std::string get_id() const { return id_; }


protected:
    std::string id_;
    int dim_;  // dimension > 0 means an array.
};

typedef VariableNode VariableExprNode;


/////////////////////////////////////////////////////////////////////////////////

class VariableDeclarationNode : public Node
{
public:
    VariableDeclarationNode( ValueType type, std::list<VariableExprNode*>* vars )
            : type_(type), vars_(vars) {}

    virtual const std::string str( ) const override {
        std::string s = std::string("(DECLARE ") + tostr(type_);
        for ( auto node : *vars_ ) {
            s +=  ' ' + tostr(node);
        }
        s += ')';
        return s;
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // Add new variable to symbol table for current scope
        // Append variable assignment instruction to TAC code for variable
        for ( auto e : *vars_ ) {
            add_to_symbol_table( data.sym_table, EntryType::Variable, data.method_name, e->get_id(), type_, "" );
            tac.append( TAC::InstrType::VAR, e->get_id() );
        }
    }

    ValueType get_type( ) const { return type_; }

    const std::list<VariableExprNode*>* get_vars() const { return vars_; }

protected:
    ValueType type_;
    const std::list<VariableExprNode*>* vars_;
};


class ParameterNode : public Node {
public:
    ParameterNode( ValueType type, VariableExprNode* var )
            : type_(type), var_(var) {}

    virtual const std::string str( ) const override {
        return std::string("(PARAM ") + tostr(type_) + tostr(var_) + ")";
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // When parameter is set for procedure it is added to symbol table
        // Append procedure-bound parameter definition instruction to TAC code for parameter
        add_to_symbol_table( data.sym_table, EntryType::Variable, data.method_name, var_->get_id(), type_, "" );
        tac.append( TAC::InstrType::FPARAM, var_->get_id() );
    }

    ValueType get_type( ) const { return type_; }

    std::string get_id() const { return var_->get_id(); }

protected:
    ValueType type_;
    VariableExprNode *var_;
};

/////////////////////////////////////////////////////////////////////////////////

class StmNode : public Node { };

class MethodCallExprStmNode: public ExprNode, public StmNode
{
public:

    MethodCallExprStmNode( std::string id, std::list<ExprNode*>* expr_list )
            : id_(id), expr_list_(expr_list) {
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // Extract value and type of each parameter passed in
        // Append TAC code that defines a value of a parameter to a procedure call
        // for each expression passed to procedure
        for ( auto e : *expr_list_ ) {
            e->icg( data, tac );
            std::string var_lhs = data.expr_return_var;
            tac.append( TAC::InstrType::APARAM, var_lhs);
        }
        // Then call procedure after defining parameters
        tac.append( TAC::InstrType::CALL, id_ );
    }

    virtual const std::string str( ) const override {
        std::string s( "(CALL " + id_ );
        for ( auto e : *expr_list_ ) {
            s += " " + tostr(e);
        }
        s += ')';
        return s;
    }

protected:
    std::string id_;
    std::list<ExprNode*> *expr_list_;
};


class AssignStmNode: public StmNode
{
public:

    AssignStmNode( VariableExprNode *lvar, ExprNode *expr )
            : lvar_(lvar), expr_(expr) {
    }

    virtual void icg( Data& data, TAC& tac ) const override {
        // Provided.
        lvar_->icg( data, tac );
        std::string var = data.expr_return_var;
        ValueType var_type = data.expr_return_type;

        expr_->icg( data, tac );
        std::string exp_var = data.expr_return_var;
        ValueType exp_type = data.expr_return_type;

        tac.append( TAC::InstrType::ASSIGN, exp_var, var );

        if ( (var_type == ValueType::RealVal && exp_type != ValueType::RealVal) ||
             (var_type != ValueType::RealVal && exp_type == ValueType::RealVal) ) {
            warning_msg("Type mismatch in assigning to variable '" + var + "'.");
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(= ") + tostr(lvar_) + ' ' + tostr(expr_) + ')';
    }

protected:
    VariableExprNode *lvar_;
    ExprNode *expr_;
};


class IncrDecrStmNode : public StmNode {};


class IncrStmNode: public IncrDecrStmNode
{
public:

    IncrStmNode( VariableExprNode *var ) : var_(var) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Evaluate and generate TAC code for expression that is being incremented
        var_->icg( data, tac );

        // In case expression resolves to real, add the value 1.0 to expression
        if ( data.expr_return_type == ValueType::RealVal ) {
            tac.append( TAC::InstrType::ADD, data.expr_return_var, "1.0", data.expr_return_var );
        }

        // In case expression resolves to int or bool, add the value 1 to expression
        else {
            tac.append( TAC::InstrType::ADD, data.expr_return_var, "1", data.expr_return_var );
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(++ ") + tostr(var_) + ')';
    }

protected:
    VariableExprNode *var_;
};


class DecrStmNode: public IncrDecrStmNode
{
public:

    DecrStmNode( VariableExprNode *var ) : var_(var) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Evaluate and generate TAC code for expression that is being decremented
        var_->icg( data, tac );

        // In case expression resolves to real, subtract the value 1.0 to expression
        if ( data.expr_return_type == ValueType::RealVal ) {
            tac.append( TAC::InstrType::SUB, data.expr_return_var, "1.0", data.expr_return_var );
        }
        // In case expression resolves to int or bool, subtract the value 1 to expression
        else {
            tac.append( TAC::InstrType::SUB, data.expr_return_var, "1", data.expr_return_var );
        }
    }

    virtual const std::string str( ) const override {
        return std::string("(-- ") + tostr(var_) + ')';
    }

protected:
    VariableExprNode *var_;
};


class ReturnStmNode: public StmNode
{
public:

    ReturnStmNode( )
            : expr_(nullptr) { }

    ReturnStmNode( ExprNode *expr )
            : expr_(expr) { }

    virtual void icg( Data& data, TAC& tac ) const override {

        // If any expression is returned, assign return value to method
        if ( expr_ != nullptr ) {
            expr_->icg( data, tac );
            tac.append( TAC::InstrType::ASSIGN, data.expr_return_var, data.method_name );
        }

        // Add return instruction to TAC code
        tac.append( TAC::InstrType::RETURN );

        SymbolTable::Entry *entry = data.sym_table.lookup("", data.method_name);
        if ( entry != nullptr ) {

            // Check if user is attempting to return value for void function (illegal)
            // Check if user is not returning value for function that should turn value (illegal)
            if ( (expr_ != nullptr && entry->value_type == ValueType::VoidVal) ||
                 (expr_ == nullptr && entry->value_type != ValueType::VoidVal) ) {
                error_msg( "Return statement in '" + data.method_name + "' does not match return value.");
            }

            // Check if return expression's type matches the type declared for method
            // (Int and Bool is considered interchangeable and mismatch between those is OK)
            if (  expr_ != nullptr &&
                 ((data.expr_return_type == ValueType::RealVal && entry->value_type != ValueType::RealVal) ||
                  (data.expr_return_type != ValueType::RealVal && entry->value_type == ValueType::RealVal)) ) {
                warning_msg( "Returned value in '" + data.method_name + "' does not match return type.");
            }
        }
    }

    virtual const std::string str( ) const override {
        std::string s("(RET ");
        if ( expr_ != nullptr ) {
            s += tostr(expr_);
        }
        s += ')';
        return s;
    }

protected:
    ExprNode *expr_;
};


class BreakStmNode: public StmNode
{
public:

    BreakStmNode(  ) { }

    virtual void icg( Data& data, TAC& tac ) const override {
        // To do ...
    }

    virtual const std::string str( ) const override {
        return std::string( "(BREAK)" );
    }
};


class ContinueStmNode: public StmNode
{
public:

    ContinueStmNode(  ) { }

    virtual void icg( Data& data, TAC& tac ) const override {
        // To do ...
    }

    virtual const std::string str( ) const override {
        return std::string( "(CONTINUE)" );
    }
};


class BlockStmNode: public StmNode
{
public:

    BlockStmNode( std::list<StmNode*>* stms ) : stms_(stms) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // To do ...
    }

    virtual const std::string str( ) const override {
        std::string s( "(BLOCK" );
        for ( auto stm : *stms_ ) {
            s += " " + tostr(stm);
        }
        s += ")";
        return s;
    };

protected:
    std::list<StmNode*>* stms_;
};


class IfStmNode: public StmNode
{
public:

    IfStmNode( ExprNode* expr, BlockStmNode* stm_if, BlockStmNode* stm_else )
            : expr_(expr), stm_if_(stm_if), stm_else_(stm_else) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // To do ...
    }

    virtual const std::string str( ) const override {
        std::string s( "(IF " );
        s += tostr(expr_) + tostr(stm_if_);
        if ( stm_else_ != nullptr ) {
            s += tostr(stm_else_);
        }
        s += ')';
        return s;
    };

protected:
    ExprNode *expr_;
    BlockStmNode *stm_if_, *stm_else_;
};


class ForStmNode: public StmNode
{
public:

    ForStmNode( AssignStmNode* assign, ExprNode* expr, IncrDecrStmNode* inc_dec,
                BlockStmNode* stms_ )
            : assign_(assign), expr_(expr), inc_dec_(inc_dec), stms_(stms_) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // To do ...
    }

    virtual const std::string str( ) const override {
        return "(FOR " + tostr(assign_) + tostr(expr_) + tostr(inc_dec_) + tostr(stms_) + ')';
    };

protected:
    AssignStmNode *assign_;
    ExprNode *expr_;
    IncrDecrStmNode *inc_dec_;
    BlockStmNode *stms_;
};

/////////////////////////////////////////////////////////////////////////////////

class MethodNode : public Node {
public:
    MethodNode( ValueType return_type,
                std::string id,
                std::list<ParameterNode*> *params,
                std::list<VariableDeclarationNode*> *vars_decl,
                std::list<StmNode*>* stms )
            : return_type_(return_type), id_(id), params_(params), vars_decl_(vars_decl), stms_(stms) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Provided.
        std::string signature;
        data.method_name = id_;
        tac.label_next_instr( data.method_name );
        for ( auto pd : *params_ ) {
            pd->icg( data, tac );
            if ( !signature.empty() ) {
                signature += "::";
            }
            signature += tostr( pd->get_type() );
        }
        // NOTE: int vs bool in signature
        add_to_symbol_table( data.sym_table, EntryType::Method, "", id_, return_type_, signature );
        // Prevent someone from using a variable with the same name as the enclosing method.
        add_to_symbol_table( data.sym_table, EntryType::Method, id_, id_, return_type_, signature );

        for ( auto vd : *vars_decl_ ) {
            vd->icg( data, tac );
        }
        for ( auto stm : *stms_ ) {
            stm->icg( data, tac );
        }
        if ( tac.last_instr_type() != TAC::InstrType::RETURN ) {
            tac.append( TAC::InstrType::RETURN );
        }
        data.method_name = "";
    }

    virtual const std::string str( ) const override {
        std::string s = "(METHOD " + tostr(return_type_) + ' ' + id_ + ' ';
        for (auto p : *params_) {
            s += tostr( p );
        }
        for (auto vds : *vars_decl_) {
            s += tostr( vds );
        }
        for (auto stm : *stms_) {
            s += tostr( stm );
        }
        s += ')';
        return s;
    }

protected:
    ValueType return_type_;
    std::string id_;
    std::list<ParameterNode*> *params_;
    std::list<VariableDeclarationNode*> *vars_decl_;
    std::list<StmNode*> *stms_;
};


class ProgramNode : public Node {
public:
    ProgramNode( std::string id,
                std::list<VariableDeclarationNode*> *var_decls,
                std::list<MethodNode*> *method_decls )
            : id_(id), var_decls_(var_decls), method_decls_(method_decls) {}

    virtual void icg( Data& data, TAC& tac ) const override {
        // Provided.
        for ( auto vd : *var_decls_ ) {
            vd->icg( data, tac );
        }
        tac.append( TAC::InstrType::GOTO, "main" );
        for ( auto md : *method_decls_ ) {
            md->icg( data, tac );
        }

        SymbolTable::Entry* entry = data.sym_table.lookup( "", "main" );
        if ( entry == nullptr || entry->entry_type != EntryType::Method) {
            error_msg( "Main method is missing." );
        }
    }

    virtual const std::string str( ) const override {
        std::string s = "(CLASS " + id_;
        if ( var_decls_ != nullptr ) {
            for (auto v : *var_decls_) {
                s += " " + tostr( v );
            }
        }
        if ( method_decls_ != nullptr ) {
            for (auto m : *method_decls_) {
                s += " " + tostr( m );
            }
        }
        s += ')';
        return s;
    }

protected:
    std::string id_;
    std::list<VariableDeclarationNode*> *var_decls_;
    std::list<MethodNode*> *method_decls_;
};

#endif //DECAFPARSER_AST_H
