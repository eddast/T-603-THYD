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
      case 48: // type
        value.copy< ValueType > (that.value);
        break;

      case 50: // variable
        value.copy< VariableNode* > (that.value);
        break;

      case 47: // variable_declarations
        value.copy< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // variable_list
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
      case 48: // type
        value.move< ValueType > (that.value);
        break;

      case 50: // variable
        value.move< VariableNode* > (that.value);
        break;

      case 47: // variable_declarations
        value.move< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // variable_list
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
      case 48: // type
        value.copy< ValueType > (that.value);
        break;

      case 50: // variable
        value.copy< VariableNode* > (that.value);
        break;

      case 47: // variable_declarations
        value.copy< std::list<VariableDeclarationNode*>* > (that.value);
        break;

      case 49: // variable_list
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
      case 48: // type
        yylhs.value.build< ValueType > ();
        break;

      case 50: // variable
        yylhs.value.build< VariableNode* > ();
        break;

      case 47: // variable_declarations
        yylhs.value.build< std::list<VariableDeclarationNode*>* > ();
        break;

      case 49: // variable_list
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
#line 90 "decaf.yy" // lalr1.cc:870
    { driver.set_AST( new ProgramNode( yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::list<VariableDeclarationNode*>* > (), nullptr ) ); }
#line 626 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 3:
#line 93 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableDeclarationNode*>* > () = yystack_[3].value.as< std::list<VariableDeclarationNode*>* > (); yylhs.value.as< std::list<VariableDeclarationNode*>* > ()->push_back( new VariableDeclarationNode(yystack_[2].value.as< ValueType > (),yystack_[1].value.as< std::list<VariableNode*>* > ()) ); }
#line 632 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 4:
#line 94 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableDeclarationNode*>* > () = new std::list<VariableDeclarationNode*>(); }
#line 638 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 5:
#line 96 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::IntVal; }
#line 644 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 6:
#line 97 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::RealVal; }
#line 650 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 7:
#line 98 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< ValueType > () = ValueType::BoolVal; }
#line 656 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 8:
#line 101 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableNode*>* > () = new std::list<VariableNode*>(); yylhs.value.as< std::list<VariableNode*>* > ()->push_back( yystack_[0].value.as< VariableNode* > () ); }
#line 662 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 9:
#line 103 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< std::list<VariableNode*>* > () = yystack_[2].value.as< std::list<VariableNode*>* > (); yylhs.value.as< std::list<VariableNode*>* > ()->push_back( yystack_[0].value.as< VariableNode* > () ); }
#line 668 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 10:
#line 105 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableNode* > () = new VariableNode(yystack_[0].value.as< std::string > ()); }
#line 674 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;

  case 11:
#line 106 "decaf.yy" // lalr1.cc:870
    { yylhs.value.as< VariableNode* > () = new VariableNode(yystack_[3].value.as< std::string > (),std::stoi(yystack_[1].value.as< std::string > ())); }
#line 680 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
    break;


#line 684 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:870
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


  const signed char parser_decaf::yypact_ninf_ = -35;

  const signed char parser_decaf::yytable_ninf_ = -1;

  const signed char
  parser_decaf::yypact_[] =
  {
       2,   -34,     7,    -7,   -35,   -35,    -6,   -35,   -35,   -35,
     -35,   -31,    -5,   -16,   -35,   -30,   -31,   -35,    -4,   -35,
     -35
  };

  const unsigned char
  parser_decaf::yydefact_[] =
  {
       0,     0,     0,     0,     1,     4,     0,     5,     6,     7,
       2,     0,    10,     0,     8,     0,     0,     3,     0,     9,
      11
  };

  const signed char
  parser_decaf::yypgoto_[] =
  {
     -35,   -35,   -35,   -35,   -35,    -3
  };

  const signed char
  parser_decaf::yydefgoto_[] =
  {
      -1,     2,     6,    11,    13,    14
  };

  const unsigned char
  parser_decaf::yytable_[] =
  {
       7,     8,     9,    16,    17,     1,     3,     4,     5,    12,
      10,    18,    15,    19,    20
  };

  const unsigned char
  parser_decaf::yycheck_[] =
  {
       6,     7,     8,    19,    20,     3,    40,     0,    15,    40,
      16,    41,    17,    16,    18
  };

  const unsigned char
  parser_decaf::yystos_[] =
  {
       0,     3,    46,    40,     0,    15,    47,     6,     7,     8,
      16,    48,    40,    49,    50,    17,    19,    20,    41,    50,
      18
  };

  const unsigned char
  parser_decaf::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50
  };

  const unsigned char
  parser_decaf::yyr2_[] =
  {
       0,     2,     5,     4,     0,     1,     1,     1,     1,     3,
       1,     4
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
  "variable_declarations", "type", "variable_list", "variable", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser_decaf::yyrline_[] =
  {
       0,    87,    87,    92,    94,    96,    97,    98,   100,   102,
     105,   106
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
#line 1068 "/Users/eddarunarsdottir/Desktop/Haust2018/THYD/Project/P2/cmake-build-debug/../parser_decaf.cpp" // lalr1.cc:1181
#line 107 "decaf.yy" // lalr1.cc:1182


////////////////////////////////////////////////////////////////////////////////////


void yy::parser_decaf::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
