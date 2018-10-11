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
      case 49: // expr
      case 50: // varExpr
      case 51: // valueExpr
        value.copy< ExprNode* > (that.value);
        break;

      case 47: // expr_list
      case 48: // more_expr
        value.copy< std::list<ExprNode*>* > (that.value);
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
      case 49: // expr
      case 50: // varExpr
      case 51: // valueExpr
        value.move< ExprNode* > (that.value);
        break;

      case 47: // expr_list
      case 48: // more_expr
        value.move< std::list<ExprNode*>* > (that.value);
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
      case 49: // expr
      case 50: // varExpr
      case 51: // valueExpr
        value.copy< ExprNode* > (that.value);
        break;

      case 47: // expr_list
      case 48: // more_expr
        value.copy< std::list<ExprNode*>* > (that.value);
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
      case 49: // expr
      case 50: // varExpr
      case 51: // valueExpr
        yylhs.value.build< ExprNode* > ();
        break;

      case 47: // expr_list
      case 48: // more_expr
        yylhs.value.build< std::list<ExprNode*>* > ();
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
#line 119 "decaf.yy" // lalr1.cc:870
    { driver.set_AST( yystack_[0].value.as< ExprNode* > () ); }
#line 606 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 3:
#line 121 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = yystack_[0].value.as< std::list<ExprNode*>* > (); yylhs.value.as< std::list<ExprNode*>* > ()->push_front( yystack_[1].value.as< ExprNode* > () ); }
#line 612 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 4:
#line 122 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = new std::list<ExprNode*>(); }
#line 618 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 5:
#line 124 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = yystack_[0].value.as< std::list<ExprNode*>* > (); yylhs.value.as< std::list<ExprNode*>* > ()->push_front( yystack_[1].value.as< ExprNode* > () ); }
#line 624 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 6:
#line 125 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<ExprNode*>* > () = new std::list<ExprNode*>(); }
#line 630 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 7:
#line 127 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new OrExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 636 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 8:
#line 128 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new AndExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 642 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 9:
#line 129 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new EqExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 648 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 10:
#line 130 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new NeqExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 654 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 11:
#line 131 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new LtExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 660 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 12:
#line 132 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new LteExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 666 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 13:
#line 133 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new GtExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 672 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 14:
#line 134 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new GteExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 678 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 15:
#line 135 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new PlusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 684 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 16:
#line 136 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MinusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 690 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 17:
#line 137 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MultiplyExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 696 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 18:
#line 138 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new DivideExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 702 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 19:
#line 139 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ModulusExprNode( yystack_[2].value.as< ExprNode* > (), yystack_[0].value.as< ExprNode* > () ); }
#line 708 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 20:
#line 141 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new PlusExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 714 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 21:
#line 143 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MinusExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 720 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 22:
#line 144 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new NotExprNode( yystack_[0].value.as< ExprNode* > () ); }
#line 726 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 23:
#line 145 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[0].value.as< ExprNode* > (); }
#line 732 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 24:
#line 146 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new MethodCallExprStmNode( yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::list<ExprNode*>* > () ); }
#line 738 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 25:
#line 147 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[0].value.as< ExprNode* > (); }
#line 744 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 26:
#line 148 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = yystack_[1].value.as< ExprNode* > (); }
#line 750 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 27:
#line 150 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new VariableExprNode( yystack_[0].value.as< std::string > () ); }
#line 756 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 28:
#line 151 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new VariableExprNode( yystack_[3].value.as< std::string > () ); }
#line 762 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 29:
#line 153 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 768 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 30:
#line 154 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 774 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 31:
#line 155 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ExprNode* > () = new ValueExprNode( yystack_[0].value.as< std::string > () ); }
#line 780 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;


#line 784 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
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


  const signed char parser_decaf::yypact_ninf_ = -32;

  const signed char parser_decaf::yytable_ninf_ = -1;

  const signed char
  parser_decaf::yypact_[] =
  {
      13,    13,    13,    13,    13,    15,   -32,   -32,   -32,     9,
      70,   -32,   -32,    55,   -32,   -32,   -32,   -31,    13,   -32,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   -32,     0,    11,    38,    14,    14,   -32,
     -32,   -32,    99,    99,   112,   112,   112,   112,   -20,    85,
     -32,   -32,    13,   -32,    38,   -32
  };

  const unsigned char
  parser_decaf::yydefact_[] =
  {
       0,     0,     0,     0,     0,    27,    29,    30,    31,     0,
       2,    23,    25,     0,    20,    21,    22,     0,     4,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     6,    15,    16,    17,
      18,    19,     9,    10,    11,    12,    13,    14,     8,     7,
      28,    24,     0,     3,     6,     5
  };

  const signed char
  parser_decaf::yypgoto_[] =
  {
     -32,   -32,   -32,   -19,    -1,   -32,   -32
  };

  const signed char
  parser_decaf::yydefgoto_[] =
  {
      -1,     9,    35,    53,    10,    11,    12
  };

  const signed char
  parser_decaf::yytable_[] =
  {
      13,    14,    15,    16,    20,    21,    22,    23,    24,    19,
      34,    25,    26,    27,    28,    29,    30,    36,    50,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    17,    51,     1,    55,    18,     2,     3,     0,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     4,     5,     6,     7,     8,    52,     0,     0,
       0,     0,    20,    21,    22,    23,    24,     0,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    20,
      21,    22,    23,    24,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    20,    21,    22,    23,    24,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    20,
      21,    22,    23,    24,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    20,    21,    22,    23,    24,     0,     0,
       0,     0,    27,    28,    29,    30,    20,    21,    22,    23,
      24,     0,     0,     0,     0,    -1,    -1,    -1,    -1
  };

  const signed char
  parser_decaf::yycheck_[] =
  {
       1,     2,     3,     4,    24,    25,    26,    27,    28,     0,
      41,    31,    32,    33,    34,    35,    36,    18,    18,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    17,    22,    21,    54,    21,    24,    25,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    39,    40,    41,    42,    43,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    22,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36
  };

  const unsigned char
  parser_decaf::yystos_[] =
  {
       0,    21,    24,    25,    39,    40,    41,    42,    43,    46,
      49,    50,    51,    49,    49,    49,    49,    17,    21,     0,
      24,    25,    26,    27,    28,    31,    32,    33,    34,    35,
      36,    37,    38,    22,    41,    47,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      18,    22,    19,    48,    49,    48
  };

  const unsigned char
  parser_decaf::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    51
  };

  const unsigned char
  parser_decaf::yyr2_[] =
  {
       0,     2,     1,     2,     0,     3,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     4,     1,     3,     1,     4,     1,
       1,     1
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
  "expr_list", "more_expr", "expr", "varExpr", "valueExpr", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser_decaf::yyrline_[] =
  {
       0,   118,   118,   121,   122,   124,   125,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   142,   144,   145,   146,   147,   148,   150,   151,   153,
     154,   155
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
#line 1209 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:1181
#line 156 "decaf.yy" // lalr1.cc:1182


////////////////////////////////////////////////////////////////////////////////////


void yy::parser_decaf::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
