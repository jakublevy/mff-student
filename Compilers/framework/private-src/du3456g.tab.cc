// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "du3456g.tab.hh"


// Unqualified %code blocks.
#line 40 "du3456g.y" // lalr1.cc:435

    #include "du3456sem.hpp"

    // this code is emitted to du3456g.cpp

    // declare yylex here 
    #include "bisonflex.hpp"
    YY_DECL;

    // allow access to context 
    #include "dutables.hpp"

    // other user-required contents
    #include <assert.h>
    #include <stdlib.h>

    /* local stuff */
    using namespace mlc;


#line 66 "du3456g.tab.cc" // lalr1.cc:435


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
    while (false)
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
#line 161 "du3456g.tab.cc" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   mlaskal_parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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
   mlaskal_parser :: mlaskal_parser  (mlc::yyscan_t2 yyscanner_yyarg, mlc::MlaskalCtx* ctx_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      yyscanner (yyscanner_yyarg),
      ctx (ctx_yyarg)
  {}

   mlaskal_parser ::~ mlaskal_parser  ()
  {}

   mlaskal_parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
   mlaskal_parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   mlaskal_parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   mlaskal_parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   mlaskal_parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   mlaskal_parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   mlaskal_parser ::symbol_number_type
   mlaskal_parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

   mlaskal_parser ::stack_symbol_type::stack_symbol_type ()
  {}

   mlaskal_parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 89: // type
        value.YY_MOVE_OR_COPY< 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > (YY_MOVE (that.value));
        break;

      case 87: // field_list
      case 88: // structured_type_3
        value.YY_MOVE_OR_COPY< 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (YY_MOVE (that.value));
        break;

      case 92: // method_parameters_opt
      case 93: // formal_parameters
        value.YY_MOVE_OR_COPY<  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (YY_MOVE (that.value));
        break;

      case 94: // var_string_opt
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 44: // FOR_DIRECTION
        value.YY_MOVE_OR_COPY< mlc::DUTOKGE_FOR_DIRECTION > (YY_MOVE (that.value));
        break;

      case 43: // OPER_MUL
        value.YY_MOVE_OR_COPY< mlc::DUTOKGE_OPER_MUL > (YY_MOVE (that.value));
        break;

      case 41: // OPER_REL
        value.YY_MOVE_OR_COPY< mlc::DUTOKGE_OPER_REL > (YY_MOVE (that.value));
        break;

      case 42: // OPER_SIGNADD
        value.YY_MOVE_OR_COPY< mlc::DUTOKGE_OPER_SIGNADD > (YY_MOVE (that.value));
        break;

      case 26: // IDENTIFIER
        value.YY_MOVE_OR_COPY< mlc::ls_id_index > (YY_MOVE (that.value));
        break;

      case 27: // UINT
        value.YY_MOVE_OR_COPY< mlc::ls_int_index > (YY_MOVE (that.value));
        break;

      case 28: // REAL
        value.YY_MOVE_OR_COPY< mlc::ls_real_index > (YY_MOVE (that.value));
        break;

      case 29: // STRING
        value.YY_MOVE_OR_COPY< mlc::ls_str_index > (YY_MOVE (that.value));
        break;

      case 85: // identifier_list_1
      case 86: // identifier_next
        value.YY_MOVE_OR_COPY< std::deque<mlc::ls_id_index> > (YY_MOVE (that.value));
        break;

      case 60: // uint_list_1
      case 61: // uint_next
        value.YY_MOVE_OR_COPY< std::deque<mlc::ls_int_index> > (YY_MOVE (that.value));
        break;

      case 62: // constant
      case 63: // unsigned_constant
        value.YY_MOVE_OR_COPY< std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   mlaskal_parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 89: // type
        value.move< 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > (YY_MOVE (that.value));
        break;

      case 87: // field_list
      case 88: // structured_type_3
        value.move< 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (YY_MOVE (that.value));
        break;

      case 92: // method_parameters_opt
      case 93: // formal_parameters
        value.move<  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (YY_MOVE (that.value));
        break;

      case 94: // var_string_opt
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 44: // FOR_DIRECTION
        value.move< mlc::DUTOKGE_FOR_DIRECTION > (YY_MOVE (that.value));
        break;

      case 43: // OPER_MUL
        value.move< mlc::DUTOKGE_OPER_MUL > (YY_MOVE (that.value));
        break;

      case 41: // OPER_REL
        value.move< mlc::DUTOKGE_OPER_REL > (YY_MOVE (that.value));
        break;

      case 42: // OPER_SIGNADD
        value.move< mlc::DUTOKGE_OPER_SIGNADD > (YY_MOVE (that.value));
        break;

      case 26: // IDENTIFIER
        value.move< mlc::ls_id_index > (YY_MOVE (that.value));
        break;

      case 27: // UINT
        value.move< mlc::ls_int_index > (YY_MOVE (that.value));
        break;

      case 28: // REAL
        value.move< mlc::ls_real_index > (YY_MOVE (that.value));
        break;

      case 29: // STRING
        value.move< mlc::ls_str_index > (YY_MOVE (that.value));
        break;

      case 85: // identifier_list_1
      case 86: // identifier_next
        value.move< std::deque<mlc::ls_id_index> > (YY_MOVE (that.value));
        break;

      case 60: // uint_list_1
      case 61: // uint_next
        value.move< std::deque<mlc::ls_int_index> > (YY_MOVE (that.value));
        break;

      case 62: // constant
      case 63: // unsigned_constant
        value.move< std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   mlaskal_parser ::stack_symbol_type&
   mlaskal_parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 89: // type
        value.move< 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > (that.value);
        break;

      case 87: // field_list
      case 88: // structured_type_3
        value.move< 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (that.value);
        break;

      case 92: // method_parameters_opt
      case 93: // formal_parameters
        value.move<  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (that.value);
        break;

      case 94: // var_string_opt
        value.move< bool > (that.value);
        break;

      case 44: // FOR_DIRECTION
        value.move< mlc::DUTOKGE_FOR_DIRECTION > (that.value);
        break;

      case 43: // OPER_MUL
        value.move< mlc::DUTOKGE_OPER_MUL > (that.value);
        break;

      case 41: // OPER_REL
        value.move< mlc::DUTOKGE_OPER_REL > (that.value);
        break;

      case 42: // OPER_SIGNADD
        value.move< mlc::DUTOKGE_OPER_SIGNADD > (that.value);
        break;

      case 26: // IDENTIFIER
        value.move< mlc::ls_id_index > (that.value);
        break;

      case 27: // UINT
        value.move< mlc::ls_int_index > (that.value);
        break;

      case 28: // REAL
        value.move< mlc::ls_real_index > (that.value);
        break;

      case 29: // STRING
        value.move< mlc::ls_str_index > (that.value);
        break;

      case 85: // identifier_list_1
      case 86: // identifier_next
        value.move< std::deque<mlc::ls_id_index> > (that.value);
        break;

      case 60: // uint_list_1
      case 61: // uint_next
        value.move< std::deque<mlc::ls_int_index> > (that.value);
        break;

      case 62: // constant
      case 63: // unsigned_constant
        value.move< std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   mlaskal_parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   mlaskal_parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   mlaskal_parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   mlaskal_parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   mlaskal_parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   mlaskal_parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   mlaskal_parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   mlaskal_parser ::debug_level_type
   mlaskal_parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   mlaskal_parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   mlaskal_parser ::state_type
   mlaskal_parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   mlaskal_parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   mlaskal_parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   mlaskal_parser ::operator() ()
  {
    return parse ();
  }

  int
   mlaskal_parser ::parse ()
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
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
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
            symbol_type yylookahead (yylex (yyscanner, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
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
  | yyreduce -- do a reduction.  |
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
      case 89: // type
        yylhs.value.emplace< 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > ();
        break;

      case 87: // field_list
      case 88: // structured_type_3
        yylhs.value.emplace< 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ();
        break;

      case 92: // method_parameters_opt
      case 93: // formal_parameters
        yylhs.value.emplace<  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ();
        break;

      case 94: // var_string_opt
        yylhs.value.emplace< bool > ();
        break;

      case 44: // FOR_DIRECTION
        yylhs.value.emplace< mlc::DUTOKGE_FOR_DIRECTION > ();
        break;

      case 43: // OPER_MUL
        yylhs.value.emplace< mlc::DUTOKGE_OPER_MUL > ();
        break;

      case 41: // OPER_REL
        yylhs.value.emplace< mlc::DUTOKGE_OPER_REL > ();
        break;

      case 42: // OPER_SIGNADD
        yylhs.value.emplace< mlc::DUTOKGE_OPER_SIGNADD > ();
        break;

      case 26: // IDENTIFIER
        yylhs.value.emplace< mlc::ls_id_index > ();
        break;

      case 27: // UINT
        yylhs.value.emplace< mlc::ls_int_index > ();
        break;

      case 28: // REAL
        yylhs.value.emplace< mlc::ls_real_index > ();
        break;

      case 29: // STRING
        yylhs.value.emplace< mlc::ls_str_index > ();
        break;

      case 85: // identifier_list_1
      case 86: // identifier_next
        yylhs.value.emplace< std::deque<mlc::ls_id_index> > ();
        break;

      case 60: // uint_list_1
      case 61: // uint_next
        yylhs.value.emplace< std::deque<mlc::ls_int_index> > ();
        break;

      case 62: // constant
      case 63: // unsigned_constant
        yylhs.value.emplace< std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
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
  case 8:
#line 146 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewLabels(ctx, yystack_[1].value.as < std::deque<mlc::ls_int_index> > ()); }
#line 900 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 11:
#line 152 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewNamedConstant(ctx, yystack_[3].value.as < mlc::ls_id_index > (), yystack_[1].value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > ()); }
#line 913 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 12:
#line 153 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewNamedConstant(ctx, yystack_[3].value.as < mlc::ls_id_index > (), yystack_[1].value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > ()); }
#line 926 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 15:
#line 160 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewType(ctx, yystack_[3].value.as < mlc::ls_id_index > (), yystack_[1].value.as < 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > ()); }
#line 936 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 16:
#line 161 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewType(ctx, yystack_[3].value.as < mlc::ls_id_index > (), yystack_[1].value.as < 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > ()); }
#line 946 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 19:
#line 168 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewVariables(ctx, yystack_[3].value.as < std::deque<mlc::ls_id_index> > (), yystack_[1].value.as < mlc::ls_id_index > ()); }
#line 952 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 20:
#line 169 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewVariables(ctx, yystack_[3].value.as < std::deque<mlc::ls_id_index> > (), yystack_[1].value.as < mlc::ls_id_index > ()); }
#line 958 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 24:
#line 176 "du3456g.y" // lalr1.cc:919
    { ctx->tab->leave(ctx->curline); }
#line 964 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 25:
#line 181 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::deque<mlc::ls_int_index> > () = yystack_[0].value.as < std::deque<mlc::ls_int_index> > (); yylhs.value.as < std::deque<mlc::ls_int_index> > ().insert(yylhs.value.as < std::deque<mlc::ls_int_index> > ().begin(), yystack_[1].value.as < mlc::ls_int_index > ()); }
#line 970 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 26:
#line 185 "du3456g.y" // lalr1.cc:919
    { /* generates an empty ls_int_index deque */ }
#line 976 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 27:
#line 186 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::deque<mlc::ls_int_index> > () = yystack_[0].value.as < std::deque<mlc::ls_int_index> > (); yylhs.value.as < std::deque<mlc::ls_int_index> > ().insert(yylhs.value.as < std::deque<mlc::ls_int_index> > ().begin(), yystack_[1].value.as < mlc::ls_int_index > ()); }
#line 982 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 28:
#line 197 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = yystack_[0].value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > (); }
#line 1002 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 29:
#line 198 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = std::make_tuple(yystack_[1].value.as < mlc::DUTOKGE_OPER_SIGNADD > (), yystack_[0].value.as < mlc::ls_int_index > ()); }
#line 1015 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 30:
#line 199 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = std::make_tuple(yystack_[1].value.as < mlc::DUTOKGE_OPER_SIGNADD > (), yystack_[0].value.as < mlc::ls_real_index > ()); }
#line 1028 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 31:
#line 211 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = yystack_[0].value.as < mlc::ls_int_index > (); }
#line 1041 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 32:
#line 212 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = yystack_[0].value.as < mlc::ls_real_index > (); }
#line 1054 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 33:
#line 213 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = yystack_[0].value.as < mlc::ls_str_index > (); }
#line 1067 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 34:
#line 214 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::variant<mlc::ls_int_index
                  , mlc::ls_real_index
                  , mlc::ls_str_index
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_int_index>
                  , std::tuple<mlc::DUTOKGE_OPER_SIGNADD, mlc::ls_real_index>
                  , bool
                   >
       > () = SemUtils::checkBoolean(ctx, yystack_[0].value.as < mlc::ls_id_index > ()); }
#line 1080 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 84:
#line 324 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::deque<mlc::ls_id_index> > () = yystack_[0].value.as < std::deque<mlc::ls_id_index> > (); yylhs.value.as < std::deque<mlc::ls_id_index> > ().insert(yylhs.value.as < std::deque<mlc::ls_id_index> > ().begin(), yystack_[1].value.as < mlc::ls_id_index > ()); }
#line 1086 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 85:
#line 327 "du3456g.y" // lalr1.cc:919
    { /* create an empty ls_id_index deque */ }
#line 1092 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 86:
#line 330 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < std::deque<mlc::ls_id_index> > () = yystack_[0].value.as < std::deque<mlc::ls_id_index> > (); yylhs.value.as < std::deque<mlc::ls_id_index> > ().insert(yylhs.value.as < std::deque<mlc::ls_id_index> > ().begin(), yystack_[1].value.as < mlc::ls_id_index > ()); }
#line 1098 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 87:
#line 338 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = yystack_[4].value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ().push_back(std::make_tuple(yystack_[2].value.as < std::deque<mlc::ls_id_index> > (), yystack_[0].value.as < mlc::ls_id_index > ())); }
#line 1113 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 88:
#line 339 "du3456g.y" // lalr1.cc:919
    { 
               yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > > {};
               yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ().push_back(std::make_tuple(yystack_[2].value.as < std::deque<mlc::ls_id_index> > (), yystack_[0].value.as < mlc::ls_id_index > ()));
           }
#line 1128 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 89:
#line 349 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = yystack_[2].value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); }
#line 1140 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 90:
#line 350 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = yystack_[1].value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); }
#line 1152 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 91:
#line 351 "du3456g.y" // lalr1.cc:919
    { /* create an empty vector */  }
#line 1158 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 92:
#line 360 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > () = yystack_[0].value.as < mlc::ls_id_index > (); }
#line 1168 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 93:
#line 361 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < 
        std::variant< std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
                    , mlc::ls_id_index
                    >
      > () = yystack_[0].value.as < 
      //  collection of                       vars               type
        std::vector<std::tuple< std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); }
#line 1181 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 94:
#line 364 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewProcedure(ctx, yystack_[2].value.as < mlc::ls_id_index > (), yystack_[1].value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ()); }
#line 1190 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 95:
#line 367 "du3456g.y" // lalr1.cc:919
    { SemUtils::addNewFunction(ctx, yystack_[4].value.as < mlc::ls_id_index > (), yystack_[3].value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (), yystack_[1].value.as < mlc::ls_id_index > ()); }
#line 1199 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 96:
#line 374 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > > {}; }
#line 1208 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 97:
#line 375 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = yystack_[1].value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); }
#line 1220 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 98:
#line 382 "du3456g.y" // lalr1.cc:919
    {
                         yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = yystack_[5].value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > (); yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ().push_back(std::make_tuple(yystack_[3].value.as < bool > (), yystack_[2].value.as < std::deque<mlc::ls_id_index> > (), yystack_[0].value.as < mlc::ls_id_index > ()));
                   }
#line 1237 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 99:
#line 385 "du3456g.y" // lalr1.cc:919
    {
                        yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > () = std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > > {};
                        yylhs.value.as <  
                          //pass by val,ref     identifiers               type
        std::vector< std::tuple< bool, std::deque<mlc::ls_id_index>, mlc::ls_id_index > >
      > ().push_back(std::make_tuple(yystack_[3].value.as < bool > (), yystack_[2].value.as < std::deque<mlc::ls_id_index> > (), yystack_[0].value.as < mlc::ls_id_index > ()));
                 }
#line 1252 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 100:
#line 392 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < bool > () = true; }
#line 1258 "du3456g.tab.cc" // lalr1.cc:919
    break;

  case 101:
#line 393 "du3456g.y" // lalr1.cc:919
    { yylhs.value.as < bool > () = false; }
#line 1264 "du3456g.tab.cc" // lalr1.cc:919
    break;


#line 1268 "du3456g.tab.cc" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

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
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
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
   mlaskal_parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
   mlaskal_parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char  mlaskal_parser ::yypact_ninf_ = -104;

  const signed char  mlaskal_parser ::yytable_ninf_ = -1;

  const signed char
   mlaskal_parser ::yypact_[] =
  {
       8,    18,    55,    33,  -104,    64,    42,  -104,    39,    67,
      43,    44,    54,  -104,    47,    70,    50,  -104,  -104,     2,
      52,    53,  -104,    64,    64,    48,    56,    57,    73,    43,
       2,    58,    46,    46,     2,    60,   -17,    62,    12,    68,
      81,  -104,  -104,    59,    59,    89,    69,    69,    11,    71,
      72,    74,    75,  -104,  -104,    93,  -104,  -104,    21,    87,
    -104,   -20,    88,    85,    76,    82,    46,    46,  -104,    84,
      86,    46,     2,  -104,  -104,   104,    83,    80,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    -2,    90,  -104,    11,
      41,    91,    94,    75,    95,  -104,    21,    23,  -104,  -104,
    -104,    46,   -11,    78,    92,     2,  -104,  -104,    46,  -104,
       2,    46,    46,  -104,    96,    79,  -104,    20,  -104,  -104,
    -104,  -104,  -104,    -3,    75,  -104,    99,  -104,  -104,  -104,
      97,     6,  -104,  -104,   100,    41,   105,  -104,    98,   107,
    -104,  -104,   101,  -104,  -104,    21,  -104,    21,  -104,   102,
    -104,  -104,  -104,   103,  -104,    46,  -104,  -104,   104,  -104,
     106,   108,  -104,  -104,   109,     0,  -104,   111,    94,   110,
     112,  -104,   -11,    78,     2,    46,    96,    75,   113,  -104,
     118,  -104,    10,  -104,  -104,   115,  -104,  -104,  -104,  -104,
     116,  -104,   114,  -104,  -104,  -104,   117,  -104,     2,   120,
     123,  -104,  -104,  -104
  };

  const unsigned char
   mlaskal_parser ::yydefact_[] =
  {
       0,     0,     0,     0,     1,     7,     0,    21,     0,     9,
      26,     0,     0,     2,     0,    13,     0,    25,     8,    76,
       0,     0,     5,     7,     7,     0,    10,     0,    17,    26,
      76,     0,    35,    35,    76,     0,    59,     0,     0,    80,
       0,    77,    67,    96,    96,     0,     0,     0,     0,     0,
       0,    14,     0,     3,    27,     0,    69,    36,     0,     0,
      37,    42,     0,     0,     0,     0,    35,    35,    68,     0,
       0,    35,    81,    79,     4,   100,     0,     0,     6,    24,
      22,    23,    34,    31,    32,    33,     0,     0,    28,     0,
       0,     0,    85,    18,     0,    70,     0,    59,    56,    57,
      58,    35,    47,    50,    52,     0,    39,    40,    35,    41,
       0,    35,    35,    65,    62,     0,    83,     0,    66,    64,
      82,    78,   101,     0,     0,    94,     0,    29,    30,    12,
       0,     0,    92,    93,     0,     0,     0,    84,     0,     0,
      55,    53,     0,    46,    45,     0,    44,     0,    49,    72,
      43,    73,    74,     0,    38,    35,    61,    60,   100,    97,
       0,     0,    11,    91,     0,     0,    16,     0,    85,     0,
       0,    54,    47,    50,     0,    35,    62,     0,     0,    95,
       0,    90,     0,    15,    86,     0,    20,    48,    51,    71,
       0,    63,     0,    99,    88,    89,     0,    19,     0,     0,
       0,    75,    98,    87
  };

  const short
   mlaskal_parser ::yypgoto_[] =
  {
    -104,  -104,   129,    77,  -104,   126,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   119,  -104,   124,    28,  -104,  -104,
     -27,   -57,  -104,   -66,  -104,    49,  -104,   -18,     7,   -15,
     -88,    63,  -104,   -21,   -54,  -103,    27,   121,  -104,   122,
     -90,   -12,  -104,  -104,    24,  -104,  -104,   125,  -104,     3
  };

  const short
   mlaskal_parser ::yydefgoto_[] =
  {
      -1,     2,    45,    22,     8,    46,     9,    15,    26,    28,
      51,    53,    93,    12,    80,    11,    17,    87,    88,    58,
      59,   153,   108,    60,   109,    61,   145,   146,   102,   148,
     103,    68,   115,   156,    38,    39,    40,    41,    73,    42,
      94,   137,   165,   133,   134,    23,    24,    76,   123,   124
  };

  const unsigned char
   mlaskal_parser ::yytable_[] =
  {
     114,   116,   149,   138,   104,   120,    62,   151,   140,   181,
      30,     1,   143,   106,    65,   163,    31,    32,    66,   195,
      33,   107,    34,    67,    35,   127,   128,   158,    36,    37,
     182,   144,    92,   159,   160,   142,    92,    82,    83,    84,
      85,   164,   104,    70,     3,    96,   154,    97,    98,    99,
     100,    65,    71,    86,    65,     4,   101,    55,    66,   173,
      67,    63,    19,     5,    20,    21,   131,   132,     6,    10,
      13,   189,    14,    25,    18,    16,    27,    29,    43,    44,
      52,    48,    49,    50,   152,    56,    64,   192,    57,   176,
      74,   104,   196,   104,    75,   201,    69,    19,    72,    79,
      91,    92,    95,   105,    89,    90,   111,   110,   113,   154,
     117,   122,   119,   125,   126,   157,   112,   130,   190,   174,
     129,   147,    78,    70,   135,   161,   136,   162,   155,   139,
     166,   168,   169,   170,     7,   198,   185,   171,   179,   193,
     178,   183,   186,   180,   194,   197,   202,   175,   199,   203,
      47,   200,   172,    54,   187,   191,   184,   150,   188,   167,
     141,   177,     0,     0,     0,     0,    81,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,   121
  };

  const short
   mlaskal_parser ::yycheck_[] =
  {
      66,    67,   105,    93,    58,    71,    33,   110,    96,     9,
       8,     3,    23,    33,    31,     9,    14,    15,    35,     9,
      18,    41,    20,    40,    22,    27,    28,    30,    26,    27,
      30,    42,    26,    36,   124,   101,    26,    26,    27,    28,
      29,   131,    96,    31,    26,    24,   112,    26,    27,    28,
      29,    31,    40,    42,    31,     0,    35,    30,    35,   147,
      40,    34,     8,    30,    10,    11,    25,    26,     4,    27,
      31,   174,     5,    26,    30,    32,     6,    27,    26,    26,
       7,    33,    26,    26,   111,    27,    26,   177,    42,   155,
       9,   145,   182,   147,    35,   198,    34,     8,    30,    30,
      26,    26,     9,    16,    33,    33,    21,    19,    26,   175,
      26,     7,    26,    30,    34,    36,    40,    89,   175,    17,
      30,    43,    45,    31,    33,    26,    32,    30,    32,    34,
      30,    26,    34,    26,     5,    19,    26,    36,    30,    26,
      34,    30,    30,    34,    26,    30,    26,    44,    34,    26,
      24,    34,   145,    29,   172,   176,   168,   108,   173,   135,
      97,   158,    -1,    -1,    -1,    -1,    47,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    72
  };

  const unsigned char
   mlaskal_parser ::yystos_[] =
  {
       0,     3,    46,    26,     0,    30,     4,    47,    49,    51,
      27,    60,    58,    31,     5,    52,    32,    61,    30,     8,
      10,    11,    48,    90,    91,    26,    53,     6,    54,    27,
       8,    14,    15,    18,    20,    22,    26,    27,    79,    80,
      81,    82,    84,    26,    26,    47,    50,    50,    33,    26,
      26,    55,     7,    56,    61,    81,    27,    42,    64,    65,
      68,    70,    65,    81,    26,    31,    35,    40,    76,    34,
      31,    40,    30,    83,     9,    35,    92,    92,    48,    30,
      59,    59,    26,    27,    28,    29,    42,    62,    63,    33,
      33,    26,    26,    57,    85,     9,    24,    26,    27,    28,
      29,    35,    73,    75,    79,    16,    33,    41,    67,    69,
      19,    21,    40,    26,    68,    77,    68,    26,    84,    26,
      68,    82,     7,    93,    94,    30,    34,    27,    28,    30,
      62,    25,    26,    88,    89,    33,    32,    86,    85,    34,
      75,    76,    68,    23,    42,    71,    72,    43,    74,    80,
      70,    80,    65,    66,    68,    32,    78,    36,    30,    36,
      85,    26,    30,     9,    85,    87,    30,    89,    26,    34,
      26,    36,    73,    75,    17,    44,    68,    94,    34,    30,
      34,     9,    30,    30,    86,    26,    30,    72,    74,    80,
      66,    78,    85,    26,    26,     9,    85,    30,    19,    34,
      34,    80,    26,    26
  };

  const unsigned char
   mlaskal_parser ::yyr1_[] =
  {
       0,    45,    46,    47,    48,    49,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    60,    61,    61,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    90,    91,    92,    92,    93,    93,
      94,    94
  };

  const unsigned char
   mlaskal_parser ::yyr2_[] =
  {
       0,     2,     5,     4,     3,     3,     2,     0,     3,     0,
       2,     5,     4,     0,     2,     5,     4,     0,     2,     5,
       4,     0,     4,     4,     1,     2,     0,     3,     1,     2,
       2,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     2,     0,     2,     3,     1,     1,     0,     3,     2,
       0,     3,     1,     2,     3,     2,     1,     1,     1,     0,
       3,     2,     0,     3,     3,     3,     3,     1,     2,     2,
       3,     6,     4,     4,     4,     8,     0,     1,     3,     2,
       0,     1,     3,     3,     2,     0,     3,     5,     3,     4,
       3,     2,     1,     1,     4,     6,     0,     3,     6,     4,
       0,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  mlaskal_parser ::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PROGRAM", "LABEL", "CONST",
  "TYPE", "VAR", "BEGIN", "END", "PROCEDURE", "FUNCTION", "ARRAY", "OF",
  "GOTO", "IF", "THEN", "ELSE", "WHILE", "DO", "REPEAT", "UNTIL", "FOR",
  "OR", "NOT", "RECORD", "IDENTIFIER", "UINT", "REAL", "STRING",
  "SEMICOLON", "DOT", "COMMA", "EQ", "COLON", "LPAR", "RPAR", "DOTDOT",
  "LSBRA", "RSBRA", "ASSIGN", "OPER_REL", "OPER_SIGNADD", "OPER_MUL",
  "FOR_DIRECTION", "$accept", "mlaskal", "block_common", "body", "block_p",
  "block", "block_p1_opt", "block_p2_opt", "block_p2_list", "block_p3_opt",
  "block_p3_list", "block_p4_opt", "block_p4_list", "block_p5_opt",
  "proc_func_end", "uint_list_1", "uint_next", "constant",
  "unsigned_constant", "pm_opt", "boolean_expression",
  "ordinal_expression", "expression_cmp", "expression", "expression_next",
  "simple_expression", "simple_expression_bin_op",
  "simple_expression_next", "term", "term_next", "factor",
  "factor_parameters_opt", "real_parameters", "real_parameters_next",
  "variable", "statement", "statement_list_opt", "statements",
  "semicolon_string_opt", "stmt_1", "identifier_list_1", "identifier_next",
  "field_list", "structured_type_3", "type", "procedure_header",
  "function_header", "method_parameters_opt", "formal_parameters",
  "var_string_opt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
   mlaskal_parser ::yyrline_[] =
  {
       0,   119,   119,   126,   131,   136,   141,   145,   146,   149,
     150,   152,   153,   156,   157,   160,   161,   164,   165,   168,
     169,   172,   173,   174,   176,   180,   185,   186,   197,   198,
     199,   211,   212,   213,   214,   217,   218,   222,   224,   227,
     228,   231,   234,   235,   238,   242,   243,   245,   246,   251,
     255,   256,   261,   265,   266,   267,   268,   269,   270,   273,
     274,   277,   280,   281,   284,   285,   289,   290,   293,   294,
     295,   296,   297,   298,   299,   302,   305,   306,   309,   310,
     313,   314,   317,   319,   323,   327,   328,   338,   339,   349,
     350,   351,   360,   361,   364,   367,   374,   375,   382,   385,
     392,   393
  };

  // Print the state stack on the debug stream.
  void
   mlaskal_parser ::yystack_print_ ()
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
   mlaskal_parser ::yy_reduce_print_ (int yyrule)
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
#line 1800 "du3456g.tab.cc" // lalr1.cc:1242
#line 395 "du3456g.y" // lalr1.cc:1243



namespace yy {

    void mlaskal_parser::error(const location_type& l, const std::string& m)
    {
        message(DUERR_SYNTAX, l, m);
    }

}

