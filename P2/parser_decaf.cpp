// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser_decaf.hpp"

// User implementation prologue.

#line 51 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:415
// Unqualified %code blocks.
#line 25 "decaf.yy" // lalr1.cc:416

#include "parser.h"

#line 57 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:416


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 152 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:491

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser_decaf::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser_decaf::parser_decaf (Parser& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  parser_decaf::~parser_decaf ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser_decaf::by_state::by_state ()
    : state (empty_state)
  {}

  parser_decaf::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser_decaf::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser_decaf::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser_decaf::by_state::by_state (state_type s)
    : state (s)
  {}

  parser_decaf::symbol_number_type
  parser_decaf::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser_decaf::stack_symbol_type::stack_symbol_type ()
  {}

  parser_decaf::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    switch (that.type_get ())
    {
      case 51: // variable_assign
        value.copy< AssignStmNode* > (that.value);
        break;

      case 59: // statement_block
      case 61: // optional_else
        value.copy< BlockStmNode* > (that.value);
        break;

      case 64: // expr
      case 66: // value_expr
        value.copy< ExprNode* > (that.value);
        break;

      case 60: // incr_decr_var
        value.copy< IncrDecrStmNode* > (that.value);
        break;

      case 53: // method_dec
        value.copy< MethodNode* > (that.value);
        break;

      case 58: // statement
        value.copy< StmNode* > (that.value);
        break;

      case 48: // type
      case 54: // method_ret_type
        value.copy< ValueType > (that.value);
        break;

      case 65: // variable_expr
        value.copy< VariableExprNode* > (that.value);
        break;

      case 50: // variable
        value.copy< VariableNode* > (that.value);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.copy< std::list<ExprNode*>* > (that.value);
        break;

      case 52: // method_decs
        value.copy< std::list<MethodNode*>* > (that.value);
        break;

      case 55: // parameters
      case 56: // parameter_list
        value.copy< std::list<ParameterNode*>* > (that.value);
        break;

      case 57: // statement_list
        value.copy< std::list<StmNode*>* > (that.value);
        break;

      case 47: // variable_decs
        value.copy< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // var_list
        value.copy< std::list<VariableNode*>* > (that.value);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

  }

  parser_decaf::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    switch (that.type_get ())
    {
      case 51: // variable_assign
        value.move< AssignStmNode* > (that.value);
        break;

      case 59: // statement_block
      case 61: // optional_else
        value.move< BlockStmNode* > (that.value);
        break;

      case 64: // expr
      case 66: // value_expr
        value.move< ExprNode* > (that.value);
        break;

      case 60: // incr_decr_var
        value.move< IncrDecrStmNode* > (that.value);
        break;

      case 53: // method_dec
        value.move< MethodNode* > (that.value);
        break;

      case 58: // statement
        value.move< StmNode* > (that.value);
        break;

      case 48: // type
      case 54: // method_ret_type
        value.move< ValueType > (that.value);
        break;

      case 65: // variable_expr
        value.move< VariableExprNode* > (that.value);
        break;

      case 50: // variable
        value.move< VariableNode* > (that.value);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.move< std::list<ExprNode*>* > (that.value);
        break;

      case 52: // method_decs
        value.move< std::list<MethodNode*>* > (that.value);
        break;

      case 55: // parameters
      case 56: // parameter_list
        value.move< std::list<ParameterNode*>* > (that.value);
        break;

      case 57: // statement_list
        value.move< std::list<StmNode*>* > (that.value);
        break;

      case 47: // variable_decs
        value.move< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // var_list
        value.move< std::list<VariableNode*>* > (that.value);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  parser_decaf::stack_symbol_type&
  parser_decaf::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 51: // variable_assign
        value.copy< AssignStmNode* > (that.value);
        break;

      case 59: // statement_block
      case 61: // optional_else
        value.copy< BlockStmNode* > (that.value);
        break;

      case 64: // expr
      case 66: // value_expr
        value.copy< ExprNode* > (that.value);
        break;

      case 60: // incr_decr_var
        value.copy< IncrDecrStmNode* > (that.value);
        break;

      case 53: // method_dec
        value.copy< MethodNode* > (that.value);
        break;

      case 58: // statement
        value.copy< StmNode* > (that.value);
        break;

      case 48: // type
      case 54: // method_ret_type
        value.copy< ValueType > (that.value);
        break;

      case 65: // variable_expr
        value.copy< VariableExprNode* > (that.value);
        break;

      case 50: // variable
        value.copy< VariableNode* > (that.value);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.copy< std::list<ExprNode*>* > (that.value);
        break;

      case 52: // method_decs
        value.copy< std::list<MethodNode*>* > (that.value);
        break;

      case 55: // parameters
      case 56: // parameter_list
        value.copy< std::list<ParameterNode*>* > (that.value);
        break;

      case 57: // statement_list
        value.copy< std::list<StmNode*>* > (that.value);
        break;

      case 47: // variable_decs
        value.copy< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // var_list
        value.copy< std::list<VariableNode*>* > (that.value);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser_decaf::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser_decaf::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser_decaf::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser_decaf::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser_decaf::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser_decaf::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser_decaf::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser_decaf::debug_level_type
  parser_decaf::debug_level () const
  {
    return yydebug_;
  }

  void
  parser_decaf::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser_decaf::state_type
  parser_decaf::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser_decaf::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser_decaf::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser_decaf::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 51: // variable_assign
        yylhs.value.build< AssignStmNode* > ();
        break;

      case 59: // statement_block
      case 61: // optional_else
        yylhs.value.build< BlockStmNode* > ();
        break;

      case 64: // expr
      case 66: // value_expr
        yylhs.value.build< ExprNode* > ();
        break;

      case 60: // incr_decr_var
        yylhs.value.build< IncrDecrStmNode* > ();
        break;

      case 53: // method_dec
        yylhs.value.build< MethodNode* > ();
        break;

      case 58: // statement
        yylhs.value.build< StmNode* > ();
        break;

      case 48: // type
      case 54: // method_ret_type
        yylhs.value.build< ValueType > ();
        break;

      case 65: // variable_expr
        yylhs.value.build< VariableExprNode* > ();
        break;

      case 50: // variable
        yylhs.value.build< VariableNode* > ();
        break;

      case 62: // expr_list
      case 63: // more_expr
        yylhs.value.build< std::list<ExprNode*>* > ();
        break;

      case 52: // method_decs
        yylhs.value.build< std::list<MethodNode*>* > ();
        break;

      case 55: // parameters
      case 56: // parameter_list
        yylhs.value.build< std::list<ParameterNode*>* > ();
        break;

      case 57: // statement_list
        yylhs.value.build< std::list<StmNode*>* > ();
        break;

      case 47: // variable_decs
        yylhs.value.build< std::list<VariableDeclarationNode*>* > ();
        break;

      case 49: // var_list
        yylhs.value.build< std::list<VariableNode*>* > ();
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 131 "decaf.yy" // lalr1.cc:870
    { driver.set_AST( new ProgramNode( yystack_[4].value.as< std::string > (), yystack_[2].value.as< std::list<VariableDeclarationNode*>* > (), yystack_[1].value.as< std::list<MethodNode*>* > () ) ); }
#line 822 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 3:
#line 133 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableDeclarationNode*>* > () = yystack_[3].value.as< std::list<VariableDeclarationNode*>* > (); yylhs.value.as< std::list<VariableDeclarationNode*>* > ()->push_back( new VariableDeclarationNode(yystack_[2].value.as< ValueType > (),yystack_[1].value.as< std::list<VariableNode*>* > ()) ); }
#line 828 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 4:
#line 134 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableDeclarationNode*>* > () = new std::list<VariableDeclarationNode*>(); }
#line 834 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 5:
#line 136 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::IntVal; }
#line 840 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 6:
#line 137 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::RealVal; }
#line 846 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 7:
#line 138 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::BoolVal; }
#line 852 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 8:
#line 140 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableNode*>* > () = new std::list<VariableNode*>(); yylhs.value.as< std::list<VariableNode*>* > ()->push_back( yystack_[0].value.as< VariableNode* > () ); }
#line 858 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 9:
#line 141 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableNode*>* > () = yystack_[2].value.as< std::list<VariableNode*>* > (); yylhs.value.as< std::list<VariableNode*>* > ()->push_back( yystack_[0].value.as< VariableNode* > () ); }
#line 864 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 10:
#line 143 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableNode* > () = new VariableNode(yystack_[0].value.as< std::string > ()); }
#line 870 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 11:
#line 144 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableNode* > () = new VariableNode(yystack_[3].value.as< std::string > (),std::stoi(yystack_[1].value.as< std::string > ())); }
#line 876 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 12:
#line 146 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< AssignStmNode* > () = new AssignStmNode( yystack_[2].value.as< VariableExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 882 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 13:
#line 148 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<MethodNode*>* > () = yystack_[1].value.as< std::list<MethodNode*>* > (); yylhs.value.as< std::list<MethodNode*>* > ()->push_back( yystack_[0].value.as< MethodNode* > () ); }
#line 888 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 14:
#line 149 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<MethodNode*>* > () = new std::list<MethodNode*>(); yylhs.value.as< std::list<MethodNode*>* > ()->push_back(yystack_[0].value.as< MethodNode* > ()); }
#line 894 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 15:
#line 154 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< MethodNode* > () = new MethodNode( yystack_[8].value.as< ValueType > (), yystack_[7].value.as< std::string > (), yystack_[5].value.as< std::list<ParameterNode*>* > (), yystack_[2].value.as< std::list<VariableDeclarationNode*>* > (), yystack_[1].value.as< std::list<StmNode*>* > () ); }
#line 900 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 16:
#line 156 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = yystack_[0].value.as< ValueType > (); }
#line 906 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 17:
#line 157 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::VoidVal; }
#line 912 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 18:
#line 159 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ParameterNode*>* > () = yystack_[0].value.as< std::list<ParameterNode*>* > (); }
#line 918 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 19:
#line 160 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ParameterNode*>* > () = new std::list<ParameterNode*>(); }
#line 924 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 20:
#line 162 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ParameterNode*>* > () = new std::list<ParameterNode*>(); yylhs.value.as< std::list<ParameterNode*>* > ()->push_back( new ParameterNode( yystack_[1].value.as< ValueType > (), yystack_[0].value.as< VariableExprNode* > () ) ); }
#line 930 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 21:
#line 163 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ParameterNode*>* > () = yystack_[3].value.as< std::list<ParameterNode*>* > (); yylhs.value.as< std::list<ParameterNode*>* > ()->push_back( new ParameterNode( yystack_[1].value.as< ValueType > (), yystack_[0].value.as< VariableExprNode* > () ) ); }
#line 936 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 22:
#line 165 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<StmNode*>* > () = yystack_[1].value.as< std::list<StmNode*>* > (); yylhs.value.as< std::list<StmNode*>* > ()->push_back( yystack_[0].value.as< StmNode* > () ); }
#line 942 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 23:
#line 166 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<StmNode*>* > () = new std::list<StmNode*>(); }
#line 948 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 24:
#line 168 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = yystack_[1].value.as< AssignStmNode* > (); }
#line 954 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 25:
#line 170 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new MethodCallExprStmNode( yystack_[4].value.as< std::string > (), yystack_[2].value.as< std::list<ExprNode*>* > () ); }
#line 960 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 26:
#line 172 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new IfStmNode( yystack_[3].value.as< ExprNode* > (), yystack_[1].value.as< BlockStmNode* > (), yystack_[0].value.as< BlockStmNode* > () ); }
#line 966 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 27:
#line 178 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new ForStmNode( yystack_[6].value.as< AssignStmNode* > (), yystack_[4].value.as< ExprNode* > (), yystack_[2].value.as< IncrDecrStmNode* > (), yystack_[0].value.as< BlockStmNode* > () ); }
#line 972 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 28:
#line 179 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new ReturnStmNode( ); }
#line 978 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 29:
#line 180 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new ReturnStmNode( yystack_[1].value.as< ExprNode* > () ); }
#line 984 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 30:
#line 181 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new BreakStmNode( ); }
#line 990 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 31:
#line 182 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = new ContinueStmNode( ); }
#line 996 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 32:
#line 183 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = yystack_[1].value.as< IncrDecrStmNode* > (); }
#line 1002 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 33:
#line 184 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< StmNode* > () = yystack_[0].value.as< BlockStmNode* > (); }
#line 1008 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 34:
#line 186 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< BlockStmNode* > () = new BlockStmNode( yystack_[1].value.as< std::list<StmNode*>* > () ); }
#line 1014 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 35:
#line 188 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< IncrDecrStmNode* > () = new IncrStmNode( yystack_[1].value.as< VariableExprNode* > () ); }
#line 1020 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 36:
#line 189 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< IncrDecrStmNode* > () = new DecrStmNode( yystack_[1].value.as< VariableExprNode* > () ); }
#line 1026 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 37:
#line 191 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< BlockStmNode* > () = yystack_[0].value.as< BlockStmNode* > (); }
#line 1032 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 38:
#line 192 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< BlockStmNode* > () = nullptr; }
#line 1038 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 39:
#line 194 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = yystack_[0].value.as< std::list<ExprNode*>* > (); yylhs.value.as< std::list<ExprNode*>* > ()->push_front( yystack_[1].value.as< ExprNode* > () ); }
#line 1044 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 40:
#line 195 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = new std::list<ExprNode*>(); }
#line 1050 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 41:
#line 197 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = yystack_[0].value.as< std::list<ExprNode*>* > (); yylhs.value.as< std::list<ExprNode*>* > ()->push_front( yystack_[1].value.as< ExprNode* > () ); }
#line 1056 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 42:
#line 198 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = new std::list<ExprNode*>(); }
#line 1062 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 43:
#line 200 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new OrExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1068 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 44:
#line 201 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new AndExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1074 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 45:
#line 202 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new EqExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1080 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 46:
#line 203 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new NeqExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1086 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 47:
#line 204 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new LtExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1092 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 48:
#line 205 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new LteExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1098 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 49:
#line 206 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new GtExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1104 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 50:
#line 207 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new GteExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1110 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 51:
#line 208 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new PlusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1116 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 52:
#line 209 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MinusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1122 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 53:
#line 210 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MultiplyExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1128 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 54:
#line 211 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new DivideExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1134 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 55:
#line 212 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ModulusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 1140 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 56:
#line 214 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new PlusExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 1146 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 57:
#line 216 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MinusExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 1152 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 58:
#line 217 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new NotExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 1158 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 59:
#line 218 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[0].value.as< VariableExprNode* > (); }
#line 1164 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 60:
#line 219 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MethodCallExprStmNode( yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::list<ExprNode*>* > () ); }
#line 1170 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 61:
#line 220 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[0].value.as< ExprNode* > (); }
#line 1176 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 62:
#line 221 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[1].value.as< ExprNode* > (); }
#line 1182 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 63:
#line 223 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableExprNode* > () = new VariableExprNode( yystack_[0].value.as< std::string > () ); }
#line 1188 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 64:
#line 224 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableExprNode* > () = new VariableExprNode( yystack_[3].value.as< std::string > () ); }
#line 1194 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 65:
#line 226 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 1200 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 66:
#line 227 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 1206 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 67:
#line 228 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 1212 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;


#line 1216 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser_decaf::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser_decaf::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser_decaf::yypact_ninf_ = -117;

  const signed char parser_decaf::yytable_ninf_ = -1;

  const short
  parser_decaf::yypact_[] =
  {
      -1,   -26,    17,    44,  -117,  -117,    73,    90,  -117,  -117,
    -117,    33,    -3,  -117,  -117,  -117,    38,    66,     5,  -117,
    -117,  -117,    64,    82,    33,  -117,    35,    86,  -117,    84,
     112,   116,  -117,   119,  -117,   127,    35,   102,  -117,    84,
     135,    35,  -117,  -117,    24,   -13,   139,   140,   149,   155,
    -117,  -117,   -12,   157,  -117,  -117,   171,    46,  -117,    47,
      47,    47,    47,    53,  -117,  -117,  -117,    94,  -117,  -117,
    -117,  -117,    47,    84,    51,    47,  -117,  -117,    47,  -117,
    -117,   130,  -117,  -117,  -117,    47,  -117,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
     147,   172,   183,  -117,   185,    75,   162,  -117,   198,    89,
      89,  -117,  -117,  -117,   204,   204,   217,   217,   217,   217,
     191,   177,   206,    47,   213,    47,  -117,  -117,   221,   113,
    -117,    75,   206,  -117,    84,  -117,  -117,   214,    63,   206,
    -117
  };

  const unsigned char
  parser_decaf::yydefact_[] =
  {
       0,     0,     0,     0,     1,     4,     0,     0,     5,     6,
       7,     0,     0,    14,    17,    16,     0,    10,     0,     8,
       2,    13,     0,     0,     0,     3,    19,     0,     9,     0,
       0,    18,    11,    63,    20,     0,     0,     0,     4,     0,
       0,    23,    21,    64,     0,     0,     0,     0,     0,     0,
      23,    15,    63,     0,    22,    33,     0,     0,    28,     0,
       0,     0,     0,    63,    65,    66,    67,     0,    59,    61,
      30,    31,     0,     0,     0,    40,    24,    32,     0,    35,
      36,     0,    56,    57,    58,    40,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    42,    12,    62,     0,    51,
      52,    53,    54,    55,    45,    46,    47,    48,    49,    50,
      44,    43,     0,     0,     0,     0,    39,    60,    38,     0,
      25,    42,     0,    26,     0,    41,    37,     0,     0,     0,
      27
  };

  const short
  parser_decaf::yypgoto_[] =
  {
    -117,  -117,   197,    -4,  -117,   222,   174,  -117,   236,  -117,
    -117,  -117,   199,  -117,  -116,   120,  -117,   170,   125,   -41,
     -29,  -117
  };

  const short
  parser_decaf::yydefgoto_[] =
  {
      -1,     2,     6,    11,    18,    19,    53,    12,    13,    16,
      30,    31,    44,    54,    55,    56,   133,   104,   126,   105,
      68,    69
  };

  const short
  parser_decaf::yytable_[] =
  {
      34,     7,     1,    15,    67,    37,   128,    58,    59,    75,
      42,    60,    61,    20,     3,    57,   136,     4,    81,    82,
      83,    84,    29,   140,    24,    25,    62,    63,    64,    65,
      66,   100,    39,    45,    46,    47,    48,   106,    49,    50,
      51,     8,     9,    10,   102,    57,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     5,
      45,    46,    47,    48,    52,    49,    50,   103,    59,    78,
      37,    60,    61,    17,    85,    79,    80,     7,    22,     8,
       9,    10,   129,    23,   131,    26,    62,    63,    64,    65,
      66,    52,    79,    80,   125,    14,     8,     9,    10,    87,
      88,    89,    90,    91,    32,   138,    92,    93,    94,    95,
      96,    97,    98,    99,    86,    89,    90,    91,    87,    88,
      89,    90,    91,    27,    33,    92,    93,    94,    95,    96,
      97,    98,    99,   134,    35,    36,    37,    87,    88,    89,
      90,    91,    38,    40,    92,    93,    94,    95,    96,    97,
      98,    99,   107,    43,    87,    88,    89,    90,    91,    70,
      71,    92,    93,    94,    95,    96,    97,    98,    99,   122,
      72,    87,    88,    89,    90,    91,    73,    76,    92,    93,
      94,    95,    96,    97,    98,    99,    87,    88,    89,    90,
      91,    77,   123,    92,    93,    94,    95,    96,    97,    98,
      99,    87,    88,    89,    90,    91,    78,   124,    92,    93,
      94,    95,    96,    97,    98,    87,    88,    89,    90,    91,
     127,    50,    92,    93,    94,    95,    96,    97,    87,    88,
      89,    90,    91,   130,   132,    41,   139,    94,    95,    96,
      97,    87,    88,    89,    90,    91,    28,   101,    21,    74,
      -1,    -1,    -1,    -1,   137,   108,   135
  };

  const unsigned char
  parser_decaf::yycheck_[] =
  {
      29,     4,     3,     7,    45,    17,   122,    20,    21,    21,
      39,    24,    25,    16,    40,    44,   132,     0,    59,    60,
      61,    62,    26,   139,    19,    20,    39,    40,    41,    42,
      43,    72,    36,     9,    10,    11,    12,    78,    14,    15,
      16,     6,     7,     8,    73,    74,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    15,
       9,    10,    11,    12,    40,    14,    15,    16,    21,    23,
      17,    24,    25,    40,    21,    29,    30,     4,    40,     6,
       7,     8,   123,    17,   125,    21,    39,    40,    41,    42,
      43,    40,    29,    30,    19,     5,     6,     7,     8,    24,
      25,    26,    27,    28,    18,   134,    31,    32,    33,    34,
      35,    36,    37,    38,    20,    26,    27,    28,    24,    25,
      26,    27,    28,    41,    40,    31,    32,    33,    34,    35,
      36,    37,    38,    20,    22,    19,    17,    24,    25,    26,
      27,    28,    15,    41,    31,    32,    33,    34,    35,    36,
      37,    38,    22,    18,    24,    25,    26,    27,    28,    20,
      20,    31,    32,    33,    34,    35,    36,    37,    38,    22,
      21,    24,    25,    26,    27,    28,    21,    20,    31,    32,
      33,    34,    35,    36,    37,    38,    24,    25,    26,    27,
      28,    20,    20,    31,    32,    33,    34,    35,    36,    37,
      38,    24,    25,    26,    27,    28,    23,    22,    31,    32,
      33,    34,    35,    36,    37,    24,    25,    26,    27,    28,
      22,    15,    31,    32,    33,    34,    35,    36,    24,    25,
      26,    27,    28,    20,    13,    38,    22,    33,    34,    35,
      36,    24,    25,    26,    27,    28,    24,    73,    12,    50,
      33,    34,    35,    36,   134,    85,   131
  };

  const unsigned char
  parser_decaf::yystos_[] =
  {
       0,     3,    46,    40,     0,    15,    47,     4,     6,     7,
       8,    48,    52,    53,     5,    48,    54,    40,    49,    50,
      16,    53,    40,    17,    19,    20,    21,    41,    50,    48,
      55,    56,    18,    40,    65,    22,    19,    17,    15,    48,
      41,    47,    65,    18,    57,     9,    10,    11,    12,    14,
      15,    16,    40,    51,    58,    59,    60,    65,    20,    21,
      24,    25,    39,    40,    41,    42,    43,    64,    65,    66,
      20,    20,    21,    21,    57,    21,    20,    20,    23,    29,
      30,    64,    64,    64,    64,    21,    20,    24,    25,    26,
      27,    28,    31,    32,    33,    34,    35,    36,    37,    38,
      64,    51,    65,    16,    62,    64,    64,    22,    62,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    22,    20,    22,    19,    63,    22,    59,    64,
      20,    64,    13,    61,    20,    63,    59,    60,    65,    22,
      59
  };

  const unsigned char
  parser_decaf::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66
  };

  const unsigned char
  parser_decaf::yyr2_[] =
  {
       0,     2,     6,     4,     0,     1,     1,     1,     1,     3,
       1,     4,     3,     2,     1,    10,     1,     1,     1,     0,
       2,     4,     2,     0,     2,     5,     6,     9,     2,     3,
       2,     2,     2,     1,     3,     2,     2,     2,     0,     2,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       4,     1,     3,     1,     4,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser_decaf::yytname_[] =
  {
  "EOI", "error", "$undefined", "kwClass", "kwStatic", "kwVoid", "kwInt",
  "kwReal", "kwBool", "kwReturn", "kwBreak", "kwContinue", "kwIf",
  "kwElse", "kwFor", "ptLBrace", "ptRBrace", "ptLBracket", "ptRBracket",
  "ptComma", "ptSemicolon", "ptLParen", "ptRParen", "OpAssign",
  "OpArtPlus", "OpArtMinus", "OpArtMult", "OpArtDiv", "OpArtModulus",
  "OpArtInc", "OpArtDec", "OpRelEQ", "OpRelNEQ", "OpRelLT", "OpRelLTE",
  "OpRelGT", "OpRelGTE", "OpLogAnd", "OpLogOr", "OpLogNot", "Identifier",
  "IntValue", "RealValue", "BoolValue", "ErrUnknown", "$accept", "program",
  "variable_decs", "type", "var_list", "variable", "variable_assign",
  "method_decs", "method_dec", "method_ret_type", "parameters",
  "parameter_list", "statement_list", "statement", "statement_block",
  "incr_decr_var", "optional_else", "expr_list", "more_expr", "expr",
  "variable_expr", "value_expr", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser_decaf::yyrline_[] =
  {
       0,   130,   130,   133,   134,   136,   137,   138,   140,   141,
     143,   144,   146,   148,   149,   151,   156,   157,   159,   160,
     162,   163,   165,   166,   168,   169,   171,   173,   179,   180,
     181,   182,   183,   184,   186,   188,   189,   191,   192,   194,
     195,   197,   198,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   215,   217,   218,
     219,   220,   221,   223,   224,   226,   227,   228
  };

  // Print the state stack on the debug stream.
  void
  parser_decaf::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser_decaf::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1707 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:1181
#line 229 "decaf.yy" // lalr1.cc:1182


////////////////////////////////////////////////////////////////////////////////////


void yy::parser_decaf::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
