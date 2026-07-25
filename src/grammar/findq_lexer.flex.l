/* findq_lexer.flex.l */

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

 // c++-style comments can start at second column outside rules section
/* c-style commens can start at first column outside rules section */

 // c++ scanner
%option c++

 // custom c++ lexer class
%option yyclass="Lexer"

 // custom prefix to rename yyFlexLexer class in flex header to FindqFlexLexer
%option prefix="Findq"

 // enable states stack
%option stack

%option warn

%option 8bit

%option debug

%option nodefault

%option never-interactive

%option noyywrap

%option nounput noinput batch

 // flex start conditions ie states
 // INITIAL 0 is default start condition
 // start conditions do not appear here in generated .cpp file
 // instead they turn into macros defined inside ylex()

%x SC_START_POINT_WHITESPACE
%x SC_START_POINT_START
%x SC_PRIMARY
%x SC_STRING_ARG_WHITESPACE
%x SC_STRING_ARG
%x SC_NUMBER_ARG_WHITESPACE
%x SC_NUMBER_ARG
%x SC_SKIP_TO_EOL

%x SC_EXEC_ARGS_WHITESPACE
%x SC_EXEC_ARGS

%top{
// appears at top of generated .cpp file

// fix flex bug vc++ warning C4005, INT8_MIN macro redefinition
#include <stdint.h>
#ifdef _WIN32
#  undef INT8_MIN
#endif

#include <string>

#ifdef _MSC_VER
#pragma warning(push)
// disable vc++ warning C4244, return conversion from streamsize to int possible loss of data, in yyFlexLexer::LexerInput() in .cpp file
#pragma warning(disable: 4244)
#endif

}

%{
// appears after flex state tables and before start state defines before yylex in generated .cpp file

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>

// bison generated header with C++ namespace and token definitions
#include "findq_parser.bison.h"
#include "lexer/findq_lexer.h"

#include "ast/findq_token_types.h"

#undef YY_DECL
#define YY_DECL findqparser::FindqParser::symbol_type findqparser::Lexer::yylex(LexParam& param)

// fix flex error could not convert 0 from int to symbol_type for #define YY_NULL 0
// caused by turning on bison %locations because symbol_type no longer has single int constructor for implicit conversion
#define yyterminate() return symbol_type(YY_NULL, loc)

using namespace std;
using namespace findqparser;

// needed for custom yyterminate
using symbol_type = FindqParser::symbol_type;

// flex start conditions appear as macros in .cpp file here

%}

 // flex rules section
 /* only c-style comments starting at second column allowed inside rules section */

%%

 // code appears inside yylex function at start

 // position in input stream
  auto& loc = param.loc;
 // update current position to previous line and column numbers
  loc.step();

  int errState = -1;
  char errChar{};


 // flex rules section
 /* only c-style comments starting at second column allowed inside rules section */
 /* first flex rule starts at beginning of line */


find {
  loc.columns(yyleng);
  yy_push_state(SC_START_POINT_WHITESPACE);
  return FindqParser::make_FIND(loc);
}

<SC_START_POINT_WHITESPACE>{
  [[:space:]]* {
    yy_pop_state();
    loc.columns(yyleng);
    yy_push_state(SC_START_POINT_START);
  }
}

 /* directory paths must not begin with any of [-!(] because these characters can be the start of a find primary term */
 /* workaround for directories that do begin with one of these characters is to use absolute paths or relative paths that start with "./" */
<SC_START_POINT_START>{
  [-!(] {
    yy_pop_state();
    yy_push_state(SC_PRIMARY);
    yyless(0);
  }

  [^-!(][[:^space:]]* {
    yy_pop_state();
    loc.columns(yyleng);
    yy_push_state(SC_START_POINT_WHITESPACE);
    return FindqParser::make_START_POINT(yytext, loc);
  }
}

<SC_PRIMARY>{

-amin {
  loc.columns(yyleng);
  return FindqParser::make_AMIN(loc);
}

-and|-a {
  loc.columns(yyleng);
  return FindqParser::make_AND(loc);
}

-anewer {
  loc.columns(yyleng);
  return FindqParser::make_ANEWER(loc);
}

-atime {
  loc.columns(yyleng);
  return FindqParser::make_ATIME(loc);
}

-cmin {
  loc.columns(yyleng);
  return FindqParser::make_CMIN(loc);
}

-cnewer {
  loc.columns(yyleng);
  return FindqParser::make_CNEWER(loc);
}

-ctime {
  loc.columns(yyleng);
  return FindqParser::make_CTIME(loc);
}

-daystart {
  loc.columns(yyleng);
  return FindqParser::make_DAYSTART(loc);
}

-delete {
  loc.columns(yyleng);
  return FindqParser::make_DELETE(loc);
}

-depth {
  loc.columns(yyleng);
  return FindqParser::make_DEPTH(loc);
}

-empty {
  loc.columns(yyleng);
  return FindqParser::make_EMPTY(loc);
}

-exec {
  loc.columns(yyleng);
  return FindqParser::make_EXEC(loc);
}

-execdir {
  loc.columns(yyleng);
  return FindqParser::make_EXECDIR(loc);
}

-executable {
  loc.columns(yyleng);
  return FindqParser::make_EXECUTABLE(loc);
}

-false {
  loc.columns(yyleng);
  return FindqParser::make_FALSE(loc);
}

-files0-from {
  loc.columns(yyleng);
  return FindqParser::make_FILES0_FROM(loc);
}

-fls {
  loc.columns(yyleng);
  return FindqParser::make_FLS(loc);
}

-follow {
  loc.columns(yyleng);
  return FindqParser::make_FOLLOW(loc);
}

-fstype {
  loc.columns(yyleng);
  return FindqParser::make_FSTYPE(loc);
}

-fprint {
  loc.columns(yyleng);
  return FindqParser::make_FPRINT(loc);
}

-fprint0 {
  loc.columns(yyleng);
  return FindqParser::make_FPRINT0(loc);
}

-fprintf {
  loc.columns(yyleng);
  return FindqParser::make_FPRINTF(loc);
}

-gid {
  loc.columns(yyleng);
  return FindqParser::make_GID(loc);
}

-group {
  loc.columns(yyleng);
  return FindqParser::make_GROUP(loc);
}

-help {
  loc.columns(yyleng);
  return FindqParser::make_HELP(loc);
}

-ignore_readdir_race {
  loc.columns(yyleng);
  return FindqParser::make_IGNORE_READDIR_RACE(loc);
}

-ilname {
  loc.columns(yyleng);
  return FindqParser::make_ILNAME(loc);
}

-iname {
  loc.columns(yyleng);
  return FindqParser::make_INAME(loc);
}

-inum {
  loc.columns(yyleng);
  return FindqParser::make_INUM(loc);
}

-ipath {
  loc.columns(yyleng);
  return FindqParser::make_IPATH(loc);
}

-iregex {
  loc.columns(yyleng);
  return FindqParser::make_IREGEX(loc);
}

-iwholename {
  loc.columns(yyleng);
  return FindqParser::make_IWHOLENAME(loc);
}

-links {
  loc.columns(yyleng);
  return FindqParser::make_LINKS(loc);
}

-lname {
  loc.columns(yyleng);
  return FindqParser::make_LNAME(loc);
}

-ls {
  loc.columns(yyleng);
  return FindqParser::make_LS(loc);
}

-maxdepth {
  loc.columns(yyleng);
  return FindqParser::make_MAXDEPTH(loc);
}

-mindepth {
  loc.columns(yyleng);
  return FindqParser::make_MINDEPTH(loc);
}

-mmin {
  loc.columns(yyleng);
  return FindqParser::make_MMIN(loc);
}

-mtime {
  loc.columns(yyleng);
  return FindqParser::make_MTIME(loc);
}

-name {
  loc.columns(yyleng);
  return FindqParser::make_NAME(loc);
}

-newer {
  loc.columns(yyleng);
  return FindqParser::make_NEWER(loc);
}

-newerXY {
  loc.columns(yyleng);
  return FindqParser::make_NEWERXY(loc);
}

-nogroup {
  loc.columns(yyleng);
  return FindqParser::make_NOGROUP(loc);
}

-not|! {
  loc.columns(yyleng);
  return FindqParser::make_NOT(loc);
}

-nouser {
  loc.columns(yyleng);
  return FindqParser::make_NOUSER(loc);
}

-ok {
  loc.columns(yyleng);
  return FindqParser::make_OK(loc);
}

-okdir {
  loc.columns(yyleng);
  return FindqParser::make_OKDIR(loc);
}

-or|-o {
  loc.columns(yyleng);
  return FindqParser::make_OR(loc);
}

-path {
  loc.columns(yyleng);
  return FindqParser::make_PATH(loc);
}

-perm {
  loc.columns(yyleng);
  return FindqParser::make_PERM(loc);
}

-prune {
  loc.columns(yyleng);
  return FindqParser::make_PRUNE(loc);
}

-print {
  loc.columns(yyleng);
  return FindqParser::make_PRINT(loc);
}

-print0 {
  loc.columns(yyleng);
  return FindqParser::make_PRINT0(loc);
}

-printf {
  loc.columns(yyleng);
  return FindqParser::make_PRINTF(loc);
}

-quit {
  loc.columns(yyleng);
  return FindqParser::make_QUIT(loc);
}

-readable {
  loc.columns(yyleng);
  return FindqParser::make_READABLE(loc);
}

-regex {
  loc.columns(yyleng);
  return FindqParser::make_REGEX(loc);
}

-samefile {
  loc.columns(yyleng);
  return FindqParser::make_SAMEFILE(loc);
}

-size {
  loc.columns(yyleng);
  return FindqParser::make_SIZE(loc);
}

-true {
  loc.columns(yyleng);
  return FindqParser::make_TRUE(loc);
}

-type {
  loc.columns(yyleng);
  return FindqParser::make_TYPE(loc);
}

-uid {
  loc.columns(yyleng);
  return FindqParser::make_UID(loc);
}

-used {
  loc.columns(yyleng);
  return FindqParser::make_USED(loc);
}

-user {
  loc.columns(yyleng);
  return FindqParser::make_USER(loc);
}

-wholename {
  loc.columns(yyleng);
  return FindqParser::make_WHOLENAME(loc);
}

-writable {
  loc.columns(yyleng);
  return FindqParser::make_WRITABLE(loc);
}

-xtype {
  loc.columns(yyleng);
  return FindqParser::make_XTYPE(loc);
}

"," {
  loc.columns(yyleng);
  return FindqParser::make_COMMA(loc);
}

"(" {
  loc.columns(yyleng);
  return FindqParser::make_LEFT_PAREN(loc);
}

")" {
  loc.columns(yyleng);
  return FindqParser::make_RIGHT_PAREN(loc);
}

 /* match newlines separately to correctly update line numbers */
\n {
  loc.lines();
}

 /* whitespace except newline, same as [ \t\v\f\r] but easier to understand */
([[:space:]]{-}[\n])+ {
  loc.columns(yyleng);
}

}

<SC_STRING_ARG_WHITESPACE>{
  [[:space:]]+ {
    yy_pop_state();
    loc.columns(yyleng);
    yy_push_state(SC_STRING_ARG);
  }
}

<SC_STRING_ARG>{
  [^"'][^[:space:]]* {
    loc.columns(yyleng);
    return FindqParser::make_STRING_ARG(yytext, loc);
  }

 /* assumes multiline string literals are not allowed */
  (?x: ["] ( ( [^"\n] | \\["] | \\\\ )* ["] ) | ( ['] ( [^'\n] | \\['] | \\\\ )* ['] ) ) {
    yy_pop_state();
    loc.columns(yyleng);
    return FindqParser::make_STRING_ARG(string(yytext + 1, yyleng - 2), loc);
  }
}

<SC_NUMBER_ARG_WHITESPACE>{
  [[:space:]]+ {
    yy_pop_state();
    loc.columns(yyleng);
    yy_push_state(SC_NUMBER_ARG);
  }
}

<SC_NUMBER_ARG>{
  [-+]?[0-9]+ {
    loc.columns(yyleng);
    const char firstChar = yytext[0];
    char* digitStart = yytext;
    int sign = 0;

    if(firstChar == '+') {
      sign = 1;
      ++digitStart;
    } else if(firstChar == '-') {
      sign = -1;
      ++digitStart;
    }
    return FindqParser::make_NUMBER_ARG({.val = (uint64_t)atoll(digitStart), .sign = sign}, loc);
  }
}

 /* lexer moves from SC_EXEC_ARGS_WHITESPACE to SC_EXEC_ARGS_WHITESPACE state and back until parser tells it to pop SC_EXEC_ARGS_WHITESPACE state */
<SC_EXEC_ARGS_WHITESPACE>{
  [[:space:]]+ {
    loc.columns(yyleng);
    yy_push_state(SC_EXEC_ARGS);
  }
}

<SC_EXEC_ARGS>{

  [^";][^[:space:]]* {
    yy_pop_state();
    loc.columns(yyleng);
    return FindqParser::make_STRING_ARG(yytext, loc);
  }

 /* assumes multiline string literals are not allowed */
  (?x: ["] ( [^"\n] | \\["] | \\\\ )* ["] ) {
    yy_pop_state();
    loc.columns(yyleng);
    return FindqParser::make_STRING_ARG(string(yytext + 1, yyleng - 2), loc);
  }

  ";" {
    yy_pop_state();
    loc.columns(yyleng);
    return FindqParser::make_SEMICOLON(loc);
  }

}

<*>.|\n {
  errChar = *yytext;
  if(errChar == '\n') {
    loc.lines();
  } else {
    loc.columns(yyleng);
  }
  errState = YY_START;
  BEGIN(SC_SKIP_TO_EOL);
}

<SC_SKIP_TO_EOL>{
  .+ {
    BEGIN(0);
    loc.columns(yyleng);
    throw FindqParser::syntax_error(loc, "bad input \""s + errChar + yytext + "\""s + " flex state " + to_string(errState));
  }
}

%%

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "lexer/findq_lexer_methods.h"
