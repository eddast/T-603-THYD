// A Bison parser, made by GNU Bison 3.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file /Users/eddarunarsdottir/Desktop/Haust2018/T-603-THYD/Project/P3/cmake-build-debug/../parser_decaf.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_USERS_EDDARUNARSDOTTIR_DESKTOP_HAUST2018_T_603_THYD_PROJECT_P3_CMAKE_BUILD_DEBUG_PARSER_DECAF_HPP_INCLUDED
# define YY_YY_USERS_EDDARUNARSDOTTIR_DESKTOP_HAUST2018_T_603_THYD_PROJECT_P3_CMAKE_BUILD_DEBUG_PARSER_DECAF_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 16 "decaf.yy" // lalr1.cc:395

#include <string>
#include "ast.h"
class Parser;

#line 50 "/Users/eddarunarsdottir/Desktop/Haust2018/T-603-THYD/Project/P3/cmake-build-debug/../parser_decaf.hpp" // lalr1.cc:395

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 134 "/Users/eddarunarsdottir/Desktop/Haust2018/T-603-THYD/Project/P3/cmake-build-debug/../parser_decaf.hpp" // lalr1.cc:395



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class parser_decaf
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // statement_block
      // optional_else
      char dummy1[sizeof(BlockStmNode*)];

      // optional_expr
      // expr
      char dummy2[sizeof(ExprNode*)];

      // incr_decr_var
      char dummy3[sizeof(IncrDecrStmNode*)];

      // method_declaration
      char dummy4[sizeof(MethodNode*)];

      // statement
      char dummy5[sizeof(StmNode*)];

      // value
      char dummy6[sizeof(ValueExprNode*)];

      // type
      // method_return_type
      char dummy7[sizeof(ValueType)];

      // variable
      char dummy8[sizeof(VariableNode*)];

      // expr_list
      // more_expr
      char dummy9[sizeof(std::list<ExprNode*>*)];

      // method_declarations
      char dummy10[sizeof(std::list<MethodNode*>*)];

      // parameters
      // parameter_list
      char dummy11[sizeof(std::list<ParameterNode*>*)];

      // statement_list
      char dummy12[sizeof(std::list<StmNode*>*)];

      // variable_declarations
      char dummy13[sizeof(std::list<VariableDeclarationNode*>*)];

      // variable_list
      char dummy14[sizeof(std::list<VariableNode*>*)];

      // Identifier
      // IntValue
      // RealValue
      // BoolValue
      // ErrUnknown
      char dummy15[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        EOI = 0,
        kwClass = 258,
        kwStatic = 259,
        kwVoid = 260,
        kwInt = 261,
        kwReal = 262,
        kwBool = 263,
        kwReturn = 264,
        kwBreak = 265,
        kwContinue = 266,
        kwIf = 267,
        kwElse = 268,
        kwFor = 269,
        ptLBrace = 270,
        ptRBrace = 271,
        ptLBracket = 272,
        ptRBracket = 273,
        ptComma = 274,
        ptSemicolon = 275,
        ptLParen = 276,
        ptRParen = 277,
        OpAssign = 278,
        OpArtPlus = 279,
        OpArtMinus = 280,
        OpArtMult = 281,
        OpArtDiv = 282,
        OpArtModulus = 283,
        OpArtInc = 284,
        OpArtDec = 285,
        OpRelEQ = 286,
        OpRelNEQ = 287,
        OpRelLT = 288,
        OpRelLTE = 289,
        OpRelGT = 290,
        OpRelGTE = 291,
        OpLogAnd = 292,
        OpLogOr = 293,
        OpLogNot = 294,
        Identifier = 295,
        IntValue = 296,
        RealValue = 297,
        BoolValue = 298,
        ErrUnknown = 299
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const BlockStmNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ExprNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IncrDecrStmNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const MethodNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const StmNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ValueExprNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ValueType& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const VariableNode*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<ExprNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<MethodNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<ParameterNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<StmNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<VariableDeclarationNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::list<VariableNode*>*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_EOI (const location_type& l);

    static inline
    symbol_type
    make_kwClass (const location_type& l);

    static inline
    symbol_type
    make_kwStatic (const location_type& l);

    static inline
    symbol_type
    make_kwVoid (const location_type& l);

    static inline
    symbol_type
    make_kwInt (const location_type& l);

    static inline
    symbol_type
    make_kwReal (const location_type& l);

    static inline
    symbol_type
    make_kwBool (const location_type& l);

    static inline
    symbol_type
    make_kwReturn (const location_type& l);

    static inline
    symbol_type
    make_kwBreak (const location_type& l);

    static inline
    symbol_type
    make_kwContinue (const location_type& l);

    static inline
    symbol_type
    make_kwIf (const location_type& l);

    static inline
    symbol_type
    make_kwElse (const location_type& l);

    static inline
    symbol_type
    make_kwFor (const location_type& l);

    static inline
    symbol_type
    make_ptLBrace (const location_type& l);

    static inline
    symbol_type
    make_ptRBrace (const location_type& l);

    static inline
    symbol_type
    make_ptLBracket (const location_type& l);

    static inline
    symbol_type
    make_ptRBracket (const location_type& l);

    static inline
    symbol_type
    make_ptComma (const location_type& l);

    static inline
    symbol_type
    make_ptSemicolon (const location_type& l);

    static inline
    symbol_type
    make_ptLParen (const location_type& l);

    static inline
    symbol_type
    make_ptRParen (const location_type& l);

    static inline
    symbol_type
    make_OpAssign (const location_type& l);

    static inline
    symbol_type
    make_OpArtPlus (const location_type& l);

    static inline
    symbol_type
    make_OpArtMinus (const location_type& l);

    static inline
    symbol_type
    make_OpArtMult (const location_type& l);

    static inline
    symbol_type
    make_OpArtDiv (const location_type& l);

    static inline
    symbol_type
    make_OpArtModulus (const location_type& l);

    static inline
    symbol_type
    make_OpArtInc (const location_type& l);

    static inline
    symbol_type
    make_OpArtDec (const location_type& l);

    static inline
    symbol_type
    make_OpRelEQ (const location_type& l);

    static inline
    symbol_type
    make_OpRelNEQ (const location_type& l);

    static inline
    symbol_type
    make_OpRelLT (const location_type& l);

    static inline
    symbol_type
    make_OpRelLTE (const location_type& l);

    static inline
    symbol_type
    make_OpRelGT (const location_type& l);

    static inline
    symbol_type
    make_OpRelGTE (const location_type& l);

    static inline
    symbol_type
    make_OpLogAnd (const location_type& l);

    static inline
    symbol_type
    make_OpLogOr (const location_type& l);

    static inline
    symbol_type
    make_OpLogNot (const location_type& l);

    static inline
    symbol_type
    make_Identifier (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_IntValue (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_RealValue (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_BoolValue (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_ErrUnknown (const std::string& v, const location_type& l);


    /// Build a parser object.
    parser_decaf (Parser& driver_yyarg);
    virtual ~parser_decaf ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser_decaf (const parser_decaf&);
    parser_decaf& operator= (const parser_decaf&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Copy construct (for efficiency).
      stack_symbol_type (const stack_symbol_type& that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 254,     ///< Last index in yytable_.
      yynnts_ = 21,  ///< Number of nonterminal symbols.
      yyfinal_ = 4, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 45  ///< Number of tokens.
    };


    // User arguments.
    Parser& driver;
  };

  // Symbol number corresponding to token number t.
  inline
  parser_decaf::token_number_type
  parser_decaf::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    const unsigned user_token_number_max_ = 299;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser_decaf::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    switch (other.type_get ())
    {
      case 59: // statement_block
      case 61: // optional_else
        value.copy< BlockStmNode* > (other.value);
        break;

      case 58: // optional_expr
      case 65: // expr
        value.copy< ExprNode* > (other.value);
        break;

      case 60: // incr_decr_var
        value.copy< IncrDecrStmNode* > (other.value);
        break;

      case 52: // method_declaration
        value.copy< MethodNode* > (other.value);
        break;

      case 57: // statement
        value.copy< StmNode* > (other.value);
        break;

      case 64: // value
        value.copy< ValueExprNode* > (other.value);
        break;

      case 48: // type
      case 53: // method_return_type
        value.copy< ValueType > (other.value);
        break;

      case 50: // variable
        value.copy< VariableNode* > (other.value);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.copy< std::list<ExprNode*>* > (other.value);
        break;

      case 51: // method_declarations
        value.copy< std::list<MethodNode*>* > (other.value);
        break;

      case 54: // parameters
      case 55: // parameter_list
        value.copy< std::list<ParameterNode*>* > (other.value);
        break;

      case 56: // statement_list
        value.copy< std::list<StmNode*>* > (other.value);
        break;

      case 47: // variable_declarations
        value.copy< std::list<VariableDeclarationNode*>* > (other.value);
        break;

      case 49: // variable_list
        value.copy< std::list<VariableNode*>* > (other.value);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
    switch (this->type_get ())
    {
      case 59: // statement_block
      case 61: // optional_else
        value.copy< BlockStmNode* > (v);
        break;

      case 58: // optional_expr
      case 65: // expr
        value.copy< ExprNode* > (v);
        break;

      case 60: // incr_decr_var
        value.copy< IncrDecrStmNode* > (v);
        break;

      case 52: // method_declaration
        value.copy< MethodNode* > (v);
        break;

      case 57: // statement
        value.copy< StmNode* > (v);
        break;

      case 64: // value
        value.copy< ValueExprNode* > (v);
        break;

      case 48: // type
      case 53: // method_return_type
        value.copy< ValueType > (v);
        break;

      case 50: // variable
        value.copy< VariableNode* > (v);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.copy< std::list<ExprNode*>* > (v);
        break;

      case 51: // method_declarations
        value.copy< std::list<MethodNode*>* > (v);
        break;

      case 54: // parameters
      case 55: // parameter_list
        value.copy< std::list<ParameterNode*>* > (v);
        break;

      case 56: // statement_list
        value.copy< std::list<StmNode*>* > (v);
        break;

      case 47: // variable_declarations
        value.copy< std::list<VariableDeclarationNode*>* > (v);
        break;

      case 49: // variable_list
        value.copy< std::list<VariableNode*>* > (v);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const BlockStmNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExprNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IncrDecrStmNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const MethodNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StmNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ValueExprNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ValueType& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VariableNode*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<ExprNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<MethodNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<ParameterNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<StmNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<VariableDeclarationNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<VariableNode*>*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser_decaf::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  parser_decaf::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser_decaf::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
  switch (yytype)
    {
      case 59: // statement_block
      case 61: // optional_else
        value.template destroy< BlockStmNode* > ();
        break;

      case 58: // optional_expr
      case 65: // expr
        value.template destroy< ExprNode* > ();
        break;

      case 60: // incr_decr_var
        value.template destroy< IncrDecrStmNode* > ();
        break;

      case 52: // method_declaration
        value.template destroy< MethodNode* > ();
        break;

      case 57: // statement
        value.template destroy< StmNode* > ();
        break;

      case 64: // value
        value.template destroy< ValueExprNode* > ();
        break;

      case 48: // type
      case 53: // method_return_type
        value.template destroy< ValueType > ();
        break;

      case 50: // variable
        value.template destroy< VariableNode* > ();
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.template destroy< std::list<ExprNode*>* > ();
        break;

      case 51: // method_declarations
        value.template destroy< std::list<MethodNode*>* > ();
        break;

      case 54: // parameters
      case 55: // parameter_list
        value.template destroy< std::list<ParameterNode*>* > ();
        break;

      case 56: // statement_list
        value.template destroy< std::list<StmNode*>* > ();
        break;

      case 47: // variable_declarations
        value.template destroy< std::list<VariableDeclarationNode*>* > ();
        break;

      case 49: // variable_list
        value.template destroy< std::list<VariableNode*>* > ();
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  bool
  parser_decaf::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser_decaf::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 59: // statement_block
      case 61: // optional_else
        value.move< BlockStmNode* > (s.value);
        break;

      case 58: // optional_expr
      case 65: // expr
        value.move< ExprNode* > (s.value);
        break;

      case 60: // incr_decr_var
        value.move< IncrDecrStmNode* > (s.value);
        break;

      case 52: // method_declaration
        value.move< MethodNode* > (s.value);
        break;

      case 57: // statement
        value.move< StmNode* > (s.value);
        break;

      case 64: // value
        value.move< ValueExprNode* > (s.value);
        break;

      case 48: // type
      case 53: // method_return_type
        value.move< ValueType > (s.value);
        break;

      case 50: // variable
        value.move< VariableNode* > (s.value);
        break;

      case 62: // expr_list
      case 63: // more_expr
        value.move< std::list<ExprNode*>* > (s.value);
        break;

      case 51: // method_declarations
        value.move< std::list<MethodNode*>* > (s.value);
        break;

      case 54: // parameters
      case 55: // parameter_list
        value.move< std::list<ParameterNode*>* > (s.value);
        break;

      case 56: // statement_list
        value.move< std::list<StmNode*>* > (s.value);
        break;

      case 47: // variable_declarations
        value.move< std::list<VariableDeclarationNode*>* > (s.value);
        break;

      case 49: // variable_list
        value.move< std::list<VariableNode*>* > (s.value);
        break;

      case 40: // Identifier
      case 41: // IntValue
      case 42: // RealValue
      case 43: // BoolValue
      case 44: // ErrUnknown
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser_decaf::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser_decaf::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser_decaf::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser_decaf::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser_decaf::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser_decaf::by_type::type_get () const
  {
    return type;
  }

  inline
  parser_decaf::token_type
  parser_decaf::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser_decaf::symbol_type
  parser_decaf::make_EOI (const location_type& l)
  {
    return symbol_type (token::EOI, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwClass (const location_type& l)
  {
    return symbol_type (token::kwClass, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwStatic (const location_type& l)
  {
    return symbol_type (token::kwStatic, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwVoid (const location_type& l)
  {
    return symbol_type (token::kwVoid, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwInt (const location_type& l)
  {
    return symbol_type (token::kwInt, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwReal (const location_type& l)
  {
    return symbol_type (token::kwReal, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwBool (const location_type& l)
  {
    return symbol_type (token::kwBool, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwReturn (const location_type& l)
  {
    return symbol_type (token::kwReturn, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwBreak (const location_type& l)
  {
    return symbol_type (token::kwBreak, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwContinue (const location_type& l)
  {
    return symbol_type (token::kwContinue, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwIf (const location_type& l)
  {
    return symbol_type (token::kwIf, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwElse (const location_type& l)
  {
    return symbol_type (token::kwElse, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_kwFor (const location_type& l)
  {
    return symbol_type (token::kwFor, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptLBrace (const location_type& l)
  {
    return symbol_type (token::ptLBrace, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptRBrace (const location_type& l)
  {
    return symbol_type (token::ptRBrace, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptLBracket (const location_type& l)
  {
    return symbol_type (token::ptLBracket, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptRBracket (const location_type& l)
  {
    return symbol_type (token::ptRBracket, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptComma (const location_type& l)
  {
    return symbol_type (token::ptComma, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptSemicolon (const location_type& l)
  {
    return symbol_type (token::ptSemicolon, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptLParen (const location_type& l)
  {
    return symbol_type (token::ptLParen, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ptRParen (const location_type& l)
  {
    return symbol_type (token::ptRParen, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpAssign (const location_type& l)
  {
    return symbol_type (token::OpAssign, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtPlus (const location_type& l)
  {
    return symbol_type (token::OpArtPlus, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtMinus (const location_type& l)
  {
    return symbol_type (token::OpArtMinus, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtMult (const location_type& l)
  {
    return symbol_type (token::OpArtMult, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtDiv (const location_type& l)
  {
    return symbol_type (token::OpArtDiv, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtModulus (const location_type& l)
  {
    return symbol_type (token::OpArtModulus, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtInc (const location_type& l)
  {
    return symbol_type (token::OpArtInc, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpArtDec (const location_type& l)
  {
    return symbol_type (token::OpArtDec, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelEQ (const location_type& l)
  {
    return symbol_type (token::OpRelEQ, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelNEQ (const location_type& l)
  {
    return symbol_type (token::OpRelNEQ, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelLT (const location_type& l)
  {
    return symbol_type (token::OpRelLT, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelLTE (const location_type& l)
  {
    return symbol_type (token::OpRelLTE, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelGT (const location_type& l)
  {
    return symbol_type (token::OpRelGT, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpRelGTE (const location_type& l)
  {
    return symbol_type (token::OpRelGTE, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpLogAnd (const location_type& l)
  {
    return symbol_type (token::OpLogAnd, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpLogOr (const location_type& l)
  {
    return symbol_type (token::OpLogOr, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_OpLogNot (const location_type& l)
  {
    return symbol_type (token::OpLogNot, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_Identifier (const std::string& v, const location_type& l)
  {
    return symbol_type (token::Identifier, v, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_IntValue (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IntValue, v, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_RealValue (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RealValue, v, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_BoolValue (const std::string& v, const location_type& l)
  {
    return symbol_type (token::BoolValue, v, l);
  }

  parser_decaf::symbol_type
  parser_decaf::make_ErrUnknown (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ErrUnknown, v, l);
  }



} // yy
#line 1800 "/Users/eddarunarsdottir/Desktop/Haust2018/T-603-THYD/Project/P3/cmake-build-debug/../parser_decaf.hpp" // lalr1.cc:395




#endif // !YY_YY_USERS_EDDARUNARSDOTTIR_DESKTOP_HAUST2018_T_603_THYD_PROJECT_P3_CMAKE_BUILD_DEBUG_PARSER_DECAF_HPP_INCLUDED
