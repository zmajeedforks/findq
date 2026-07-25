// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 211 "./src/grammar/findq_parser.bison.y"

// % code top
// appears as topmost code block in generated .cpp file just below gnu license
// your license for .cpp file
/*
MIT License

Copyright (c) 2024-2026 Zartaj Majeed

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#line 69 "findq_parser.bison.cpp"


// First part of user prologue.
#line 241 "./src/grammar/findq_parser.bison.y"

// %{ unnamed codeblock
// goes at top of .cpp file after %code top, before namespace and parser class


#line 79 "findq_parser.bison.cpp"


#include "findq_parser.bison.h"


// Unqualified %code blocks.
#line 247 "./src/grammar/findq_parser.bison.y"

// %code
// appears in generated .cpp file after #include of generated .h file and before parser namespace and class

#include <string>
#include <chrono>

#include "ast/findq_ast.h"

#ifdef _MSC_VER
// disable vc++ warning C4065, switch statement contains default but no other case labels when there are no semantic actions
#pragma warning(push)
#pragma warning(disable: 4065)

// disable vc++ warning C4244, return conversion from const short to findqparser::FindqParser::state_type, possible loss of data
#pragma warning(push)
#pragma warning(disable: 4244)
#endif

using namespace std;
using findqparser::FindqParser;

namespace {
  const auto defaultInputName = "inputstream"s;
}

void FindqParser::error(const location& loc, const string& msg) {
  println("error at {}: {}", loc, msg);
}

// needed for %define parse.error custom
void FindqParser::report_syntax_error(const FindqParser::context& ctx) const {
  auto n = ctx.expected_tokens(NULL, 0);
  vector<FindqParser::symbol_kind_type> expectedTokens(n);
  ctx.expected_tokens(expectedTokens.data(), n);
  string expectedTokensList;
  for(auto i = 0; i < n - 1; ++i) {
    expectedTokensList += string(FindqParser::symbol_name(expectedTokens[i])) + ", ";
  }
  expectedTokensList += FindqParser::symbol_name(expectedTokens[n - 1]);
  stringstream loc;
  loc << ctx.location();
  print(stderr, "FindqParser.report_syntax_error: location \"{}\" token \"{}\" lookahead \"{}\" expected tokens \"{}\" \n", loc.str(), FindqParser::symbol_name(ctx.token()), ctx.lookahead().name(), expectedTokensList);
}


#line 133 "findq_parser.bison.cpp"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 164 "./src/grammar/findq_parser.bison.y"
namespace findqparser {
#line 226 "findq_parser.bison.cpp"

  /// Build a parser object.
  FindqParser::FindqParser (function<FindqParser::symbol_type(LexParam&)> yylex_yyarg, BisonParam& bisonParam_yyarg, LexParam& lexParam_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yylex (yylex_yyarg),
      bisonParam (bisonParam_yyarg),
      lexParam (lexParam_yyarg)
  {}

  FindqParser::~FindqParser ()
  {}

  FindqParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  FindqParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  FindqParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  FindqParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  FindqParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  FindqParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  FindqParser::symbol_kind_type
  FindqParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  FindqParser::stack_symbol_type::stack_symbol_type ()
  {}

  FindqParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.YY_MOVE_OR_COPY< AndExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmd: // cmd
        value.YY_MOVE_OR_COPY< Cmd > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.YY_MOVE_OR_COPY< CommaExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_findq: // findq
        value.YY_MOVE_OR_COPY< Findq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.YY_MOVE_OR_COPY< NumberArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.YY_MOVE_OR_COPY< OrExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.YY_MOVE_OR_COPY< Primary > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< Term > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.YY_MOVE_OR_COPY< Unit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmds: // cmds
        value.YY_MOVE_OR_COPY< vector<Cmd> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.YY_MOVE_OR_COPY< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  FindqParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.move< AndExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmd: // cmd
        value.move< Cmd > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.move< CommaExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_findq: // findq
        value.move< Findq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.move< NumberArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.move< OrExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.move< Primary > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.move< Term > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.move< Unit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.move< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmds: // cmds
        value.move< vector<Cmd> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.move< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  FindqParser::stack_symbol_type&
  FindqParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.copy< AndExpr > (that.value);
        break;

      case symbol_kind::S_cmd: // cmd
        value.copy< Cmd > (that.value);
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.copy< CommaExpr > (that.value);
        break;

      case symbol_kind::S_findq: // findq
        value.copy< Findq > (that.value);
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.copy< NumberArg > (that.value);
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.copy< OrExpr > (that.value);
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.copy< Primary > (that.value);
        break;

      case symbol_kind::S_term: // term
        value.copy< Term > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.copy< Unit > (that.value);
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.copy< string > (that.value);
        break;

      case symbol_kind::S_cmds: // cmds
        value.copy< vector<Cmd> > (that.value);
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.copy< vector<string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  FindqParser::stack_symbol_type&
  FindqParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.move< AndExpr > (that.value);
        break;

      case symbol_kind::S_cmd: // cmd
        value.move< Cmd > (that.value);
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.move< CommaExpr > (that.value);
        break;

      case symbol_kind::S_findq: // findq
        value.move< Findq > (that.value);
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.move< NumberArg > (that.value);
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.move< OrExpr > (that.value);
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.move< Primary > (that.value);
        break;

      case symbol_kind::S_term: // term
        value.move< Term > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.move< Unit > (that.value);
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.move< string > (that.value);
        break;

      case symbol_kind::S_cmds: // cmds
        value.move< vector<Cmd> > (that.value);
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.move< vector<string> > (that.value);
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
  FindqParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  FindqParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  FindqParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  FindqParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  FindqParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  FindqParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  FindqParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  FindqParser::debug_level_type
  FindqParser::debug_level () const
  {
    return yydebug_;
  }

  void
  FindqParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  FindqParser::state_type
  FindqParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  FindqParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  FindqParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  FindqParser::operator() ()
  {
    return parse ();
  }

  int
  FindqParser::parse ()
  {
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


    // User initialization code.
#line 294 "./src/grammar/findq_parser.bison.y"
{
// %initial-action codeblock
// goes inside parse() function in .cpp, it's a separate brace-scoped block, anything declared here is local to this block and cannot be used anywhere else in parse()

// suppress unused variable warning till fix in release after version 3.8.2, https://github.com/akimd/bison/commit/a166d5450e3f47587b98f6005f9f5627dbe21a5b
// yynerrs_ is local to generated parse function
  (void)yynerrs_;

  bisonParam.stats.parseStartTime = steady_clock::now();

  auto& loc = lexParam.loc;

  if(loc.begin.filename == nullptr) {
    loc.initialize(&defaultInputName);
  }
}

#line 718 "findq_parser.bison.cpp"


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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (lexParam));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case symbol_kind::S_and_expr: // and_expr
        yylhs.value.emplace< AndExpr > ();
        break;

      case symbol_kind::S_cmd: // cmd
        yylhs.value.emplace< Cmd > ();
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        yylhs.value.emplace< CommaExpr > ();
        break;

      case symbol_kind::S_findq: // findq
        yylhs.value.emplace< Findq > ();
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        yylhs.value.emplace< NumberArg > ();
        break;

      case symbol_kind::S_or_expr: // or_expr
        yylhs.value.emplace< OrExpr > ();
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        yylhs.value.emplace< Primary > ();
        break;

      case symbol_kind::S_term: // term
        yylhs.value.emplace< Term > ();
        break;

      case symbol_kind::S_unit: // unit
        yylhs.value.emplace< Unit > ();
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        yylhs.value.emplace< string > ();
        break;

      case symbol_kind::S_cmds: // cmds
        yylhs.value.emplace< vector<Cmd> > ();
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        yylhs.value.emplace< vector<string> > ();
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
  case 2: // findq: cmds
#line 440 "./src/grammar/findq_parser.bison.y"
            {
  yylhs.value.as < Findq > ().cmds = move(yystack_[0].value.as < vector<Cmd> > ());
}
#line 911 "findq_parser.bison.cpp"
    break;

  case 3: // cmds: cmd
#line 445 "./src/grammar/findq_parser.bison.y"
      {
  yylhs.value.as < vector<Cmd> > ().push_back(move(yystack_[0].value.as < Cmd > ()));
}
#line 919 "findq_parser.bison.cpp"
    break;

  case 4: // cmds: cmds cmd
#line 448 "./src/grammar/findq_parser.bison.y"
           {
  yylhs.value.as < vector<Cmd> > () = move(yystack_[1].value.as < vector<Cmd> > ());
  yylhs.value.as < vector<Cmd> > ().push_back(move(yystack_[0].value.as < Cmd > ()));
}
#line 928 "findq_parser.bison.cpp"
    break;

  case 5: // cmd: "find" comma_expr
#line 454 "./src/grammar/findq_parser.bison.y"
                   {
  yylhs.value.as < Cmd > ().expr = move(yystack_[0].value.as < CommaExpr > ());
}
#line 936 "findq_parser.bison.cpp"
    break;

  case 6: // cmd: "find" start_points comma_expr
#line 457 "./src/grammar/findq_parser.bison.y"
                                 {
  yylhs.value.as < Cmd > ().expr = move(yystack_[0].value.as < CommaExpr > ());
}
#line 944 "findq_parser.bison.cpp"
    break;

  case 7: // comma_expr: or_expr
#line 462 "./src/grammar/findq_parser.bison.y"
          {
  yylhs.value.as < CommaExpr > ().segs.push_back(move(yystack_[0].value.as < OrExpr > ()));
}
#line 952 "findq_parser.bison.cpp"
    break;

  case 8: // comma_expr: comma_expr "," or_expr
#line 465 "./src/grammar/findq_parser.bison.y"
                         {
  yylhs.value.as < CommaExpr > () = move(yystack_[2].value.as < CommaExpr > ());
  yylhs.value.as < CommaExpr > ().segs.push_back(move(yystack_[0].value.as < OrExpr > ()));
}
#line 961 "findq_parser.bison.cpp"
    break;

  case 9: // or_expr: and_expr
#line 471 "./src/grammar/findq_parser.bison.y"
           {
  yylhs.value.as < OrExpr > ().ors.push_back(move(yystack_[0].value.as < AndExpr > ()));
}
#line 969 "findq_parser.bison.cpp"
    break;

  case 10: // or_expr: or_expr "-o" and_expr
#line 474 "./src/grammar/findq_parser.bison.y"
                        {
  yylhs.value.as < OrExpr > () = move(yystack_[2].value.as < OrExpr > ());
  yylhs.value.as < OrExpr > ().ors.push_back(move(yystack_[0].value.as < AndExpr > ()));
}
#line 978 "findq_parser.bison.cpp"
    break;

  case 11: // and_expr: term
#line 480 "./src/grammar/findq_parser.bison.y"
       {
  yylhs.value.as < AndExpr > ().ands.push_back(move(yystack_[0].value.as < Term > ()));

}
#line 987 "findq_parser.bison.cpp"
    break;

  case 12: // and_expr: and_expr and_op term
#line 484 "./src/grammar/findq_parser.bison.y"
                       {
  yylhs.value.as < AndExpr > () = move(yystack_[2].value.as < AndExpr > ());
  yylhs.value.as < AndExpr > ().ands.push_back(move(yystack_[0].value.as < Term > ()));
}
#line 996 "findq_parser.bison.cpp"
    break;

  case 13: // term: unit
#line 490 "./src/grammar/findq_parser.bison.y"
       {
  yylhs.value.as < Term > ().unit = move(yystack_[0].value.as < Unit > ());
}
#line 1004 "findq_parser.bison.cpp"
    break;

  case 14: // term: "!" unit
#line 493 "./src/grammar/findq_parser.bison.y"
           {
  yylhs.value.as < Term > ().unit = move(yystack_[0].value.as < Unit > ());
  yylhs.value.as < Term > ().isTrue = false;
}
#line 1013 "findq_parser.bison.cpp"
    break;

  case 15: // unit: primary
#line 499 "./src/grammar/findq_parser.bison.y"
          {
  yylhs.value.as < Unit > () = move(yystack_[0].value.as < Primary > ());
}
#line 1021 "findq_parser.bison.cpp"
    break;

  case 16: // unit: group
#line 502 "./src/grammar/findq_parser.bison.y"
        {
}
#line 1028 "findq_parser.bison.cpp"
    break;

  case 18: // primary: test
#line 508 "./src/grammar/findq_parser.bison.y"
       { yylhs.value.as < Primary > () = move(yystack_[0].value.as < Primary > ()); }
#line 1034 "findq_parser.bison.cpp"
    break;

  case 19: // primary: action
#line 509 "./src/grammar/findq_parser.bison.y"
         { yylhs.value.as < Primary > () = move(yystack_[0].value.as < Primary > ()); }
#line 1040 "findq_parser.bison.cpp"
    break;

  case 20: // primary: global_opt
#line 510 "./src/grammar/findq_parser.bison.y"
             { yylhs.value.as < Primary > () = move(yystack_[0].value.as < Primary > ()); }
#line 1046 "findq_parser.bison.cpp"
    break;

  case 21: // primary: positional_opt
#line 511 "./src/grammar/findq_parser.bison.y"
                 { yylhs.value.as < Primary > () = move(yystack_[0].value.as < Primary > ()); }
#line 1052 "findq_parser.bison.cpp"
    break;

  case 26: // test: "-amin" NUMBER_ARG
#line 518 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Amin{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1060 "findq_parser.bison.cpp"
    break;

  case 27: // test: "-anewer" STRING_ARG
#line 521 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Anewer{move(yystack_[0].value.as < string > ())};
}
#line 1068 "findq_parser.bison.cpp"
    break;

  case 28: // test: "-atime" NUMBER_ARG
#line 524 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Atime{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1076 "findq_parser.bison.cpp"
    break;

  case 29: // test: "-cmin" NUMBER_ARG
#line 527 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Cmin{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1084 "findq_parser.bison.cpp"
    break;

  case 30: // test: "-cnewer" STRING_ARG
#line 530 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Cnewer{move(yystack_[0].value.as < string > ())};
}
#line 1092 "findq_parser.bison.cpp"
    break;

  case 31: // test: "-ctime" NUMBER_ARG
#line 533 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Ctime{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1100 "findq_parser.bison.cpp"
    break;

  case 32: // test: "-empty"
#line 536 "./src/grammar/findq_parser.bison.y"
           {
  yylhs.value.as < Primary > () = Empty{};
}
#line 1108 "findq_parser.bison.cpp"
    break;

  case 33: // test: "-executable"
#line 539 "./src/grammar/findq_parser.bison.y"
                {
  yylhs.value.as < Primary > () = Executable{};
}
#line 1116 "findq_parser.bison.cpp"
    break;

  case 34: // test: "-false"
#line 542 "./src/grammar/findq_parser.bison.y"
           {
  yylhs.value.as < Primary > () = False{};
}
#line 1124 "findq_parser.bison.cpp"
    break;

  case 35: // test: "-fstype" STRING_ARG
#line 545 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Fstype{move(yystack_[0].value.as < string > ())};
}
#line 1132 "findq_parser.bison.cpp"
    break;

  case 36: // test: "-gid" NUMBER_ARG
#line 548 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Gid{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1140 "findq_parser.bison.cpp"
    break;

  case 37: // test: "-group" STRING_ARG
#line 551 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Group{move(yystack_[0].value.as < string > ())};
}
#line 1148 "findq_parser.bison.cpp"
    break;

  case 38: // test: "-ilname" STRING_ARG
#line 554 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Ilname{move(yystack_[0].value.as < string > ())};
}
#line 1156 "findq_parser.bison.cpp"
    break;

  case 39: // test: "-iname" STRING_ARG
#line 557 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Iname{move(yystack_[0].value.as < string > ())};
}
#line 1164 "findq_parser.bison.cpp"
    break;

  case 40: // test: "-inum" NUMBER_ARG
#line 560 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Inum{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1172 "findq_parser.bison.cpp"
    break;

  case 41: // test: "-ipath" STRING_ARG
#line 563 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Ipath{move(yystack_[0].value.as < string > ())};
}
#line 1180 "findq_parser.bison.cpp"
    break;

  case 42: // test: "-iregex" STRING_ARG
#line 566 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Iregex{move(yystack_[0].value.as < string > ())};
}
#line 1188 "findq_parser.bison.cpp"
    break;

  case 43: // test: "-iwholename" STRING_ARG
#line 569 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Iwholename{move(yystack_[0].value.as < string > ())};
}
#line 1196 "findq_parser.bison.cpp"
    break;

  case 44: // test: "-links" NUMBER_ARG
#line 572 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Links{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1204 "findq_parser.bison.cpp"
    break;

  case 45: // test: "-lname" STRING_ARG
#line 575 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Lname{move(yystack_[0].value.as < string > ())};
}
#line 1212 "findq_parser.bison.cpp"
    break;

  case 46: // test: "-mmin" NUMBER_ARG
#line 578 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Mmin{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1220 "findq_parser.bison.cpp"
    break;

  case 47: // test: "-mtime" NUMBER_ARG
#line 581 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Mtime{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1228 "findq_parser.bison.cpp"
    break;

  case 48: // test: "-name" STRING_ARG
#line 584 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Name{move(yystack_[0].value.as < string > ())};
}
#line 1236 "findq_parser.bison.cpp"
    break;

  case 49: // test: "-newer" STRING_ARG
#line 587 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Newer{move(yystack_[0].value.as < string > ())};
}
#line 1244 "findq_parser.bison.cpp"
    break;

  case 50: // test: "-newerXY" STRING_ARG
#line 590 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = NewerXY{move(yystack_[0].value.as < string > ())};
}
#line 1252 "findq_parser.bison.cpp"
    break;

  case 51: // test: "-nogroup"
#line 593 "./src/grammar/findq_parser.bison.y"
             {
  yylhs.value.as < Primary > () = NoGroup{};
}
#line 1260 "findq_parser.bison.cpp"
    break;

  case 52: // test: "-nouser"
#line 596 "./src/grammar/findq_parser.bison.y"
            {
  yylhs.value.as < Primary > () = NoUser{};
}
#line 1268 "findq_parser.bison.cpp"
    break;

  case 53: // test: "-path" STRING_ARG
#line 599 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Path{move(yystack_[0].value.as < string > ())};
}
#line 1276 "findq_parser.bison.cpp"
    break;

  case 54: // test: "-perm" STRING_ARG
#line 602 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Perm{move(yystack_[0].value.as < string > ())};
}
#line 1284 "findq_parser.bison.cpp"
    break;

  case 55: // test: "-readable"
#line 605 "./src/grammar/findq_parser.bison.y"
              {
  yylhs.value.as < Primary > () = Readable{};
}
#line 1292 "findq_parser.bison.cpp"
    break;

  case 56: // test: "-regex" STRING_ARG
#line 608 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Regex{move(yystack_[0].value.as < string > ())};
}
#line 1300 "findq_parser.bison.cpp"
    break;

  case 57: // test: "-samefile"
#line 611 "./src/grammar/findq_parser.bison.y"
              {
  yylhs.value.as < Primary > () = Samefile{};
}
#line 1308 "findq_parser.bison.cpp"
    break;

  case 58: // test: "-size" NUMBER_ARG
#line 614 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Size{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1316 "findq_parser.bison.cpp"
    break;

  case 59: // test: "-true"
#line 617 "./src/grammar/findq_parser.bison.y"
          {
  yylhs.value.as < Primary > () = True{};
}
#line 1324 "findq_parser.bison.cpp"
    break;

  case 60: // test: "-type" STRING_ARG
#line 620 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Type{move(yystack_[0].value.as < string > ())};
}
#line 1332 "findq_parser.bison.cpp"
    break;

  case 61: // test: "-uid" NUMBER_ARG
#line 623 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Uid{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1340 "findq_parser.bison.cpp"
    break;

  case 62: // test: "-used" NUMBER_ARG
#line 626 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Used{move(yystack_[0].value.as < NumberArg > ())};
}
#line 1348 "findq_parser.bison.cpp"
    break;

  case 63: // test: "-user" STRING_ARG
#line 629 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = User{move(yystack_[0].value.as < string > ())};
}
#line 1356 "findq_parser.bison.cpp"
    break;

  case 64: // test: "-wholename" STRING_ARG
#line 632 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Wholename{move(yystack_[0].value.as < string > ())};
}
#line 1364 "findq_parser.bison.cpp"
    break;

  case 65: // test: "-writable"
#line 635 "./src/grammar/findq_parser.bison.y"
              {
  yylhs.value.as < Primary > () = Writable{};
}
#line 1372 "findq_parser.bison.cpp"
    break;

  case 66: // test: "-xtype" STRING_ARG
#line 638 "./src/grammar/findq_parser.bison.y"
                                          {
  yylhs.value.as < Primary > () = Xtype{move(yystack_[0].value.as < string > ())};
}
#line 1380 "findq_parser.bison.cpp"
    break;

  case 67: // action: "-delete"
#line 643 "./src/grammar/findq_parser.bison.y"
            {}
#line 1386 "findq_parser.bison.cpp"
    break;

  case 68: // action: "-exec" EXEC_ARG
#line 644 "./src/grammar/findq_parser.bison.y"
                                        {}
#line 1392 "findq_parser.bison.cpp"
    break;

  case 69: // action: "-execdir" EXEC_ARG
#line 645 "./src/grammar/findq_parser.bison.y"
                                        {}
#line 1398 "findq_parser.bison.cpp"
    break;

  case 70: // action: "-fls" STRING_ARG
#line 646 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1404 "findq_parser.bison.cpp"
    break;

  case 71: // action: "-fprint" STRING_ARG
#line 647 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1410 "findq_parser.bison.cpp"
    break;

  case 72: // action: "-fprint0" STRING_ARG
#line 648 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1416 "findq_parser.bison.cpp"
    break;

  case 73: // action: "-fprintf" STRING_ARG
#line 649 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1422 "findq_parser.bison.cpp"
    break;

  case 74: // action: "-ls"
#line 650 "./src/grammar/findq_parser.bison.y"
        {}
#line 1428 "findq_parser.bison.cpp"
    break;

  case 75: // action: "-ok" EXEC_ARG
#line 651 "./src/grammar/findq_parser.bison.y"
                                        {}
#line 1434 "findq_parser.bison.cpp"
    break;

  case 76: // action: "-okdir" EXEC_ARG
#line 652 "./src/grammar/findq_parser.bison.y"
                                        {}
#line 1440 "findq_parser.bison.cpp"
    break;

  case 77: // action: "-print"
#line 653 "./src/grammar/findq_parser.bison.y"
           {}
#line 1446 "findq_parser.bison.cpp"
    break;

  case 78: // action: "-print0"
#line 654 "./src/grammar/findq_parser.bison.y"
            {}
#line 1452 "findq_parser.bison.cpp"
    break;

  case 79: // action: "-printf" STRING_ARG
#line 655 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1458 "findq_parser.bison.cpp"
    break;

  case 80: // action: "-prune"
#line 656 "./src/grammar/findq_parser.bison.y"
           {}
#line 1464 "findq_parser.bison.cpp"
    break;

  case 81: // action: "-quit"
#line 657 "./src/grammar/findq_parser.bison.y"
          {}
#line 1470 "findq_parser.bison.cpp"
    break;

  case 82: // global_opt: "-depth"
#line 660 "./src/grammar/findq_parser.bison.y"
           {}
#line 1476 "findq_parser.bison.cpp"
    break;

  case 83: // global_opt: "-files0-from" STRING_ARG
#line 661 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1482 "findq_parser.bison.cpp"
    break;

  case 84: // global_opt: "-help"
#line 662 "./src/grammar/findq_parser.bison.y"
          {}
#line 1488 "findq_parser.bison.cpp"
    break;

  case 85: // global_opt: "-ignore_readdir_race"
#line 663 "./src/grammar/findq_parser.bison.y"
                         {}
#line 1494 "findq_parser.bison.cpp"
    break;

  case 86: // global_opt: "-maxdepth" NUMBER_ARG
#line 664 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1500 "findq_parser.bison.cpp"
    break;

  case 87: // global_opt: "-mindepth" NUMBER_ARG
#line 665 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1506 "findq_parser.bison.cpp"
    break;

  case 88: // global_opt: "-mount"
#line 666 "./src/grammar/findq_parser.bison.y"
           {}
#line 1512 "findq_parser.bison.cpp"
    break;

  case 89: // global_opt: "-noignore_readdir_race"
#line 667 "./src/grammar/findq_parser.bison.y"
                           {}
#line 1518 "findq_parser.bison.cpp"
    break;

  case 90: // global_opt: "-noleaf"
#line 668 "./src/grammar/findq_parser.bison.y"
            {}
#line 1524 "findq_parser.bison.cpp"
    break;

  case 91: // global_opt: "-xdev"
#line 669 "./src/grammar/findq_parser.bison.y"
          {}
#line 1530 "findq_parser.bison.cpp"
    break;

  case 92: // positional_opt: "-daystart"
#line 672 "./src/grammar/findq_parser.bison.y"
              {}
#line 1536 "findq_parser.bison.cpp"
    break;

  case 93: // positional_opt: "-follow"
#line 673 "./src/grammar/findq_parser.bison.y"
            {}
#line 1542 "findq_parser.bison.cpp"
    break;

  case 94: // positional_opt: "-nowarn"
#line 674 "./src/grammar/findq_parser.bison.y"
            {}
#line 1548 "findq_parser.bison.cpp"
    break;

  case 95: // positional_opt: "-regextype" STRING_ARG
#line 675 "./src/grammar/findq_parser.bison.y"
                                          {}
#line 1554 "findq_parser.bison.cpp"
    break;

  case 96: // positional_opt: "-warn"
#line 676 "./src/grammar/findq_parser.bison.y"
          {}
#line 1560 "findq_parser.bison.cpp"
    break;


#line 1564 "findq_parser.bison.cpp"

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
        context yyctx (*this, yyla);
        report_syntax_error (yyctx);
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
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
    YY_STACK_PRINT ();
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
  FindqParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  FindqParser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "find", "-amin", "-anewer",
  "-atime", "-cmin", "-cnewer", "-ctime", "-empty", "-executable",
  "-false", "-fstype", "-gid", "-group", "-ilname", "-iname", "-inum",
  "-ipath", "-iregex", "-iwholename", "-links", "-lname", "-mmin",
  "-mtime", "-name", "-newer", "-newerXY", "-nogroup", "-nouser", "-path",
  "-perm", "-readable", "-regex", "-samefile", "-size", "-true", "-type",
  "-uid", "-used", "-user", "-wholename", "-writable", "-xtype", "-delete",
  "-exec", "-execdir", "-fls", "-fprint", "-fprint0", "-fprintf", "-ls",
  "-ok", "-okdir", "-print", "-print0", "-printf", "-prune", "-quit",
  "-depth", "-files0-from", "-help", "-ignore_readdir_race", "-maxdepth",
  "-mindepth", "-mount", "-noignore_readdir_race", "-noleaf", "-xdev",
  "-daystart", "-follow", "-nowarn", "-regextype", "-warn", "!", "-a",
  "-o", ",", "(", ")", ";", "NUMBER_ARG", "STRING_ARG", "EXEC_ARG",
  "START_POINT", "$accept", "findq", "cmds", "cmd", "comma_expr",
  "or_expr", "and_expr", "term", "unit", "group", "primary", "and_op",
  "start_points", "test", "action", "global_opt", "positional_opt", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // FindqParser::context.
  FindqParser::context::context (const FindqParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  FindqParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }








  const signed char FindqParser::yypact_ninf_ = -7;

  const signed char FindqParser::yytable_ninf_ = -11;

  const short
  FindqParser::yypact_[] =
  {
      70,    -4,    76,    70,    -7,    -5,    -3,    72,    77,    83,
      80,    -7,    -7,    -7,    84,    86,    87,    88,    89,    91,
      92,    93,    94,    96,    97,    99,   100,   101,   102,   103,
      -7,    -7,   104,   105,    -7,   106,    -7,   108,    -7,   109,
     111,   112,   113,   114,    -7,   115,    -7,    85,    90,   116,
     117,   118,   119,    -7,    95,   107,    -7,    -7,   120,    -7,
      -7,    -7,   121,    -7,    -7,   123,   124,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,   125,    -7,   314,   238,    -7,     0,
       2,   155,    -7,    -7,    -7,    -7,    78,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -6,
     238,   238,    -7,   238,    -7,     0,    -7,     2,   161,    -7
  };

  const signed char
  FindqParser::yydefact_[] =
  {
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    52,     0,     0,    55,     0,    57,     0,    59,     0,
       0,     0,     0,     0,    65,     0,    67,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    77,    78,     0,    80,
      81,    82,     0,    84,    85,     0,     0,    88,    89,    90,
      91,    92,    93,    94,     0,    96,     0,     0,    24,     5,
       7,    22,    11,    13,    16,    15,     0,    18,    19,    20,
      21,     1,     4,    26,    27,    28,    29,    30,    31,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    53,    54,    56,    58,    60,
      61,    62,    63,    64,    66,    68,    69,    70,    71,    72,
      73,    75,    76,    79,    83,    86,    87,    95,    14,     0,
       0,     0,    23,     0,    25,     6,    17,     8,    22,    12
  };

  const short
  FindqParser::yypgoto_[] =
  {
      -7,    -7,    -7,   157,    79,    43,    54,    64,   133,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7
  };

  const unsigned char
  FindqParser::yydefgoto_[] =
  {
       0,     2,     3,     4,    79,    80,    81,    82,    83,    84,
      85,   143,    86,    87,    88,    89,    90
  };

  const short
  FindqParser::yytable_[] =
  {
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   140,     1,   146,    77,    91,    93,   140,   141,
      94,    78,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    95,    -9,   139,    77,    -9,    96,
      92,   -10,    98,   144,   -10,   145,    97,    99,   100,   125,
     101,   102,   103,   104,   126,   105,   106,   107,   108,   131,
     109,   110,   111,   147,   112,   113,   114,   115,   116,   117,
     118,   132,   119,   120,   121,   148,   122,   123,   124,   127,
     128,   129,   130,   133,   134,   135,   136,   149,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,    -9,    -9,     0,    -9,     0,   142,   -10,   -10,
       0,   -10,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    77,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,    77
  };

  const short
  FindqParser::yycheck_[] =
  {
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    78,     3,    80,    79,     0,    82,    78,    77,
      83,    85,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    82,     0,    77,    79,     3,    82,
       3,     0,    82,    85,     3,    86,    83,    83,    82,    84,
      83,    83,    83,    82,    84,    83,    83,    83,    82,    84,
      83,    82,    82,   140,    83,    83,    83,    83,    83,    83,
      82,    84,    83,    82,    82,   141,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    82,    82,   143,    83,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    -1,    80,    -1,    76,    77,    78,
      -1,    80,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    79
  };

  const signed char
  FindqParser::yystos_[] =
  {
       0,     3,    87,    88,    89,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    79,    85,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     102,     0,    89,    82,    83,    82,    82,    83,    82,    83,
      82,    83,    83,    83,    82,    83,    83,    83,    82,    83,
      82,    82,    83,    83,    83,    83,    83,    83,    82,    83,
      82,    82,    83,    83,    83,    84,    84,    83,    83,    83,
      83,    84,    84,    83,    83,    82,    82,    83,    94,    90,
      78,    77,    76,    97,    85,    90,    80,    91,    92,    93
  };

  const signed char
  FindqParser::yyr1_[] =
  {
       0,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102
  };

  const signed char
  FindqParser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     0,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     2,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     1,     2,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1
  };




#if YYDEBUG
  const short
  FindqParser::yyrline_[] =
  {
       0,   440,   440,   445,   448,   454,   457,   462,   465,   471,
     474,   480,   484,   490,   493,   499,   502,   505,   508,   509,
     510,   511,   513,   513,   515,   515,   518,   521,   524,   527,
     530,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   566,   569,   572,   575,   578,   581,   584,   587,
     590,   593,   596,   599,   602,   605,   608,   611,   614,   617,
     620,   623,   626,   629,   632,   635,   638,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   672,   673,   674,   675,   676
  };

  void
  FindqParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  FindqParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
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


#line 164 "./src/grammar/findq_parser.bison.y"
} // findqparser
#line 2062 "findq_parser.bison.cpp"

#line 841 "./src/grammar/findq_parser.bison.y"

// %code epilog block
// goes at bottom of generated .cpp file after namespace and parser implementation


#ifdef _MSC_VER
#pragma warning(pop)
#pragma warning(pop)
#endif

