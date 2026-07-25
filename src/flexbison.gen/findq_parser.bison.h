// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file findq_parser.bison.h
 ** Define the findqparser::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_FINDQ_PARSER_BISON_H_INCLUDED
# define YY_YY_FINDQ_PARSER_BISON_H_INCLUDED
// "%code requires" blocks.
#line 57 "./src/grammar/findq_parser.bison.y"

// %code requires codeblock goes at top of .h outside of namespace and parser class
// your license for .h file, standard c++ #includes and defines

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

#include <string>
#include <vector>
#include <functional>
#include <chrono>
#include <variant>
#include <optional>
#include <print>

#include "locations.bison.h"

#include "ast/findq_token_types.h"
#include "ast/findq_ast.h"

#ifdef _MSC_VER
// disable vc++ warning C4065, switch statement contains default but no case labels in code generated for basic_symbol::clear() in .h file
#pragma warning(push)
#pragma warning(disable: 4065)
#endif

namespace findqparser {
using namespace std;
using namespace chrono;

#if 0
struct NumberArg {
  int sign = 0;
  uint64_t val;
  auto operator<=>(const NumberArg&) const = default;
};
#endif

struct RuleCallbacks {
  optional<function<void(void)>> binary_expression_from_and_cb{};
  optional<function<void(void)>> and_expression_from_list_cb{};
  optional<function<void(void)>> unary_expression_from_not_cb{};
  optional<function<void(const string&)>> string_arg_cb{};
};

struct BisonParam {
  FindqAstNode ast;

  RuleCallbacks ruleCb;
  struct Stats {
    time_point<steady_clock> parseStartTime;
    time_point<steady_clock> parseEndTime;
    duration<double> parseTimeSec;
  } stats;
};

// info for lexer to use in yylex
struct LexParam {
// position in input stream for lexer to update
  location loc{};
};

#if 0
OptionsMap curPositionalOptions = defaultPositionalOptions;
#endif

}

// println formatter for location object
template<>
struct std::formatter<findqparser::location> {
  std::format_context::iterator format(const findqparser::location& loc, std::format_context& ctx) const {
    std::ostringstream os;
    os << loc;
    return std::format_to(ctx.out(), "{}", os.str());
  }

  constexpr std::format_parse_context::const_iterator parse(std::format_parse_context& ctx) const {
    return ctx.begin();
  }
};



#line 155 "findq_parser.bison.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "locations.bison.h"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 164 "./src/grammar/findq_parser.bison.y"
namespace findqparser {
#line 296 "findq_parser.bison.h"




  /// A Bison parser.
  class FindqParser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
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
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // and_expr
      char dummy1[sizeof (AndExpr)];

      // cmd
      char dummy2[sizeof (Cmd)];

      // comma_expr
      char dummy3[sizeof (CommaExpr)];

      // findq
      char dummy4[sizeof (Findq)];

      // NUMBER_ARG
      char dummy5[sizeof (NumberArg)];

      // or_expr
      char dummy6[sizeof (OrExpr)];

      // primary
      // test
      // action
      // global_opt
      // positional_opt
      char dummy7[sizeof (Primary)];

      // term
      char dummy8[sizeof (Term)];

      // unit
      char dummy9[sizeof (Unit)];

      // STRING_ARG
      // START_POINT
      char dummy10[sizeof (string)];

      // cmds
      char dummy11[sizeof (vector<Cmd>)];

      // EXEC_ARG
      char dummy12[sizeof (vector<string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    FIND = 3,                      // "find"
    AMIN = 4,                      // "-amin"
    ANEWER = 5,                    // "-anewer"
    ATIME = 6,                     // "-atime"
    CMIN = 7,                      // "-cmin"
    CNEWER = 8,                    // "-cnewer"
    CTIME = 9,                     // "-ctime"
    EMPTY = 10,                    // "-empty"
    EXECUTABLE = 11,               // "-executable"
    FALSE = 12,                    // "-false"
    FSTYPE = 13,                   // "-fstype"
    GID = 14,                      // "-gid"
    GROUP = 15,                    // "-group"
    ILNAME = 16,                   // "-ilname"
    INAME = 17,                    // "-iname"
    INUM = 18,                     // "-inum"
    IPATH = 19,                    // "-ipath"
    IREGEX = 20,                   // "-iregex"
    IWHOLENAME = 21,               // "-iwholename"
    LINKS = 22,                    // "-links"
    LNAME = 23,                    // "-lname"
    MMIN = 24,                     // "-mmin"
    MTIME = 25,                    // "-mtime"
    NAME = 26,                     // "-name"
    NEWER = 27,                    // "-newer"
    NEWERXY = 28,                  // "-newerXY"
    NOGROUP = 29,                  // "-nogroup"
    NOUSER = 30,                   // "-nouser"
    PATH = 31,                     // "-path"
    PERM = 32,                     // "-perm"
    READABLE = 33,                 // "-readable"
    REGEX = 34,                    // "-regex"
    SAMEFILE = 35,                 // "-samefile"
    SIZE = 36,                     // "-size"
    TRUE = 37,                     // "-true"
    TYPE = 38,                     // "-type"
    UID = 39,                      // "-uid"
    USED = 40,                     // "-used"
    USER = 41,                     // "-user"
    WHOLENAME = 42,                // "-wholename"
    WRITABLE = 43,                 // "-writable"
    XTYPE = 44,                    // "-xtype"
    DELETE = 45,                   // "-delete"
    EXEC = 46,                     // "-exec"
    EXECDIR = 47,                  // "-execdir"
    FLS = 48,                      // "-fls"
    FPRINT = 49,                   // "-fprint"
    FPRINT0 = 50,                  // "-fprint0"
    FPRINTF = 51,                  // "-fprintf"
    LS = 52,                       // "-ls"
    OK = 53,                       // "-ok"
    OKDIR = 54,                    // "-okdir"
    PRINT = 55,                    // "-print"
    PRINT0 = 56,                   // "-print0"
    PRINTF = 57,                   // "-printf"
    PRUNE = 58,                    // "-prune"
    QUIT = 59,                     // "-quit"
    DEPTH = 60,                    // "-depth"
    FILES0_FROM = 61,              // "-files0-from"
    HELP = 62,                     // "-help"
    IGNORE_READDIR_RACE = 63,      // "-ignore_readdir_race"
    MAXDEPTH = 64,                 // "-maxdepth"
    MINDEPTH = 65,                 // "-mindepth"
    MOUNT = 66,                    // "-mount"
    NOIGNORE_READDIR_RACE = 67,    // "-noignore_readdir_race"
    NOLEAF = 68,                   // "-noleaf"
    XDEV = 69,                     // "-xdev"
    DAYSTART = 70,                 // "-daystart"
    FOLLOW = 71,                   // "-follow"
    NOWARN = 72,                   // "-nowarn"
    REGEXTYPE = 73,                // "-regextype"
    WARN = 74,                     // "-warn"
    NOT = 75,                      // "!"
    AND = 76,                      // "-a"
    OR = 77,                       // "-o"
    COMMA = 78,                    // ","
    LEFT_PAREN = 79,               // "("
    RIGHT_PAREN = 80,              // ")"
    SEMICOLON = 81,                // ";"
    NUMBER_ARG = 82,               // NUMBER_ARG
    STRING_ARG = 83,               // STRING_ARG
    EXEC_ARG = 84,                 // EXEC_ARG
    START_POINT = 85               // START_POINT
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 86, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_FIND = 3,                              // "find"
        S_AMIN = 4,                              // "-amin"
        S_ANEWER = 5,                            // "-anewer"
        S_ATIME = 6,                             // "-atime"
        S_CMIN = 7,                              // "-cmin"
        S_CNEWER = 8,                            // "-cnewer"
        S_CTIME = 9,                             // "-ctime"
        S_EMPTY = 10,                            // "-empty"
        S_EXECUTABLE = 11,                       // "-executable"
        S_FALSE = 12,                            // "-false"
        S_FSTYPE = 13,                           // "-fstype"
        S_GID = 14,                              // "-gid"
        S_GROUP = 15,                            // "-group"
        S_ILNAME = 16,                           // "-ilname"
        S_INAME = 17,                            // "-iname"
        S_INUM = 18,                             // "-inum"
        S_IPATH = 19,                            // "-ipath"
        S_IREGEX = 20,                           // "-iregex"
        S_IWHOLENAME = 21,                       // "-iwholename"
        S_LINKS = 22,                            // "-links"
        S_LNAME = 23,                            // "-lname"
        S_MMIN = 24,                             // "-mmin"
        S_MTIME = 25,                            // "-mtime"
        S_NAME = 26,                             // "-name"
        S_NEWER = 27,                            // "-newer"
        S_NEWERXY = 28,                          // "-newerXY"
        S_NOGROUP = 29,                          // "-nogroup"
        S_NOUSER = 30,                           // "-nouser"
        S_PATH = 31,                             // "-path"
        S_PERM = 32,                             // "-perm"
        S_READABLE = 33,                         // "-readable"
        S_REGEX = 34,                            // "-regex"
        S_SAMEFILE = 35,                         // "-samefile"
        S_SIZE = 36,                             // "-size"
        S_TRUE = 37,                             // "-true"
        S_TYPE = 38,                             // "-type"
        S_UID = 39,                              // "-uid"
        S_USED = 40,                             // "-used"
        S_USER = 41,                             // "-user"
        S_WHOLENAME = 42,                        // "-wholename"
        S_WRITABLE = 43,                         // "-writable"
        S_XTYPE = 44,                            // "-xtype"
        S_DELETE = 45,                           // "-delete"
        S_EXEC = 46,                             // "-exec"
        S_EXECDIR = 47,                          // "-execdir"
        S_FLS = 48,                              // "-fls"
        S_FPRINT = 49,                           // "-fprint"
        S_FPRINT0 = 50,                          // "-fprint0"
        S_FPRINTF = 51,                          // "-fprintf"
        S_LS = 52,                               // "-ls"
        S_OK = 53,                               // "-ok"
        S_OKDIR = 54,                            // "-okdir"
        S_PRINT = 55,                            // "-print"
        S_PRINT0 = 56,                           // "-print0"
        S_PRINTF = 57,                           // "-printf"
        S_PRUNE = 58,                            // "-prune"
        S_QUIT = 59,                             // "-quit"
        S_DEPTH = 60,                            // "-depth"
        S_FILES0_FROM = 61,                      // "-files0-from"
        S_HELP = 62,                             // "-help"
        S_IGNORE_READDIR_RACE = 63,              // "-ignore_readdir_race"
        S_MAXDEPTH = 64,                         // "-maxdepth"
        S_MINDEPTH = 65,                         // "-mindepth"
        S_MOUNT = 66,                            // "-mount"
        S_NOIGNORE_READDIR_RACE = 67,            // "-noignore_readdir_race"
        S_NOLEAF = 68,                           // "-noleaf"
        S_XDEV = 69,                             // "-xdev"
        S_DAYSTART = 70,                         // "-daystart"
        S_FOLLOW = 71,                           // "-follow"
        S_NOWARN = 72,                           // "-nowarn"
        S_REGEXTYPE = 73,                        // "-regextype"
        S_WARN = 74,                             // "-warn"
        S_NOT = 75,                              // "!"
        S_AND = 76,                              // "-a"
        S_OR = 77,                               // "-o"
        S_COMMA = 78,                            // ","
        S_LEFT_PAREN = 79,                       // "("
        S_RIGHT_PAREN = 80,                      // ")"
        S_SEMICOLON = 81,                        // ";"
        S_NUMBER_ARG = 82,                       // NUMBER_ARG
        S_STRING_ARG = 83,                       // STRING_ARG
        S_EXEC_ARG = 84,                         // EXEC_ARG
        S_START_POINT = 85,                      // START_POINT
        S_YYACCEPT = 86,                         // $accept
        S_findq = 87,                            // findq
        S_cmds = 88,                             // cmds
        S_cmd = 89,                              // cmd
        S_comma_expr = 90,                       // comma_expr
        S_or_expr = 91,                          // or_expr
        S_and_expr = 92,                         // and_expr
        S_term = 93,                             // term
        S_unit = 94,                             // unit
        S_group = 95,                            // group
        S_primary = 96,                          // primary
        S_and_op = 97,                           // and_op
        S_start_points = 98,                     // start_points
        S_test = 99,                             // test
        S_action = 100,                          // action
        S_global_opt = 101,                      // global_opt
        S_positional_opt = 102                   // positional_opt
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.move< AndExpr > (std::move (that.value));
        break;

      case symbol_kind::S_cmd: // cmd
        value.move< Cmd > (std::move (that.value));
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.move< CommaExpr > (std::move (that.value));
        break;

      case symbol_kind::S_findq: // findq
        value.move< Findq > (std::move (that.value));
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.move< NumberArg > (std::move (that.value));
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.move< OrExpr > (std::move (that.value));
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.move< Primary > (std::move (that.value));
        break;

      case symbol_kind::S_term: // term
        value.move< Term > (std::move (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.move< Unit > (std::move (that.value));
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.move< string > (std::move (that.value));
        break;

      case symbol_kind::S_cmds: // cmds
        value.move< vector<Cmd> > (std::move (that.value));
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.move< vector<string> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AndExpr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AndExpr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Cmd&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Cmd& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CommaExpr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CommaExpr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Findq&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Findq& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NumberArg&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NumberArg& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, OrExpr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const OrExpr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Primary&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Primary& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Term&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Term& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Unit&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Unit& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<Cmd>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<Cmd>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_and_expr: // and_expr
        value.template destroy< AndExpr > ();
        break;

      case symbol_kind::S_cmd: // cmd
        value.template destroy< Cmd > ();
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.template destroy< CommaExpr > ();
        break;

      case symbol_kind::S_findq: // findq
        value.template destroy< Findq > ();
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.template destroy< NumberArg > ();
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.template destroy< OrExpr > ();
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.template destroy< Primary > ();
        break;

      case symbol_kind::S_term: // term
        value.template destroy< Term > ();
        break;

      case symbol_kind::S_unit: // unit
        value.template destroy< Unit > ();
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.template destroy< string > ();
        break;

      case symbol_kind::S_cmds: // cmds
        value.template destroy< vector<Cmd> > ();
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.template destroy< vector<string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return FindqParser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::SEMICOLON));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, NumberArg v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const NumberArg& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::NUMBER_ARG);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::STRING_ARG
                   || tok == token::START_POINT);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, vector<string> v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const vector<string>& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::EXEC_ARG);
#endif
      }
    };

    /// Build a parser object.
    FindqParser (function<FindqParser::symbol_type(LexParam&)> yylex_yyarg, BisonParam& bisonParam_yyarg, LexParam& lexParam_yyarg);
    virtual ~FindqParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    FindqParser (const FindqParser&) = delete;
    /// Non copyable.
    FindqParser& operator= (const FindqParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

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

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIND (location_type l)
      {
        return symbol_type (token::FIND, std::move (l));
      }
#else
      static
      symbol_type
      make_FIND (const location_type& l)
      {
        return symbol_type (token::FIND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMIN (location_type l)
      {
        return symbol_type (token::AMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_AMIN (const location_type& l)
      {
        return symbol_type (token::AMIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANEWER (location_type l)
      {
        return symbol_type (token::ANEWER, std::move (l));
      }
#else
      static
      symbol_type
      make_ANEWER (const location_type& l)
      {
        return symbol_type (token::ANEWER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATIME (location_type l)
      {
        return symbol_type (token::ATIME, std::move (l));
      }
#else
      static
      symbol_type
      make_ATIME (const location_type& l)
      {
        return symbol_type (token::ATIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CMIN (location_type l)
      {
        return symbol_type (token::CMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_CMIN (const location_type& l)
      {
        return symbol_type (token::CMIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CNEWER (location_type l)
      {
        return symbol_type (token::CNEWER, std::move (l));
      }
#else
      static
      symbol_type
      make_CNEWER (const location_type& l)
      {
        return symbol_type (token::CNEWER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CTIME (location_type l)
      {
        return symbol_type (token::CTIME, std::move (l));
      }
#else
      static
      symbol_type
      make_CTIME (const location_type& l)
      {
        return symbol_type (token::CTIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EMPTY (location_type l)
      {
        return symbol_type (token::EMPTY, std::move (l));
      }
#else
      static
      symbol_type
      make_EMPTY (const location_type& l)
      {
        return symbol_type (token::EMPTY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXECUTABLE (location_type l)
      {
        return symbol_type (token::EXECUTABLE, std::move (l));
      }
#else
      static
      symbol_type
      make_EXECUTABLE (const location_type& l)
      {
        return symbol_type (token::EXECUTABLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FSTYPE (location_type l)
      {
        return symbol_type (token::FSTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_FSTYPE (const location_type& l)
      {
        return symbol_type (token::FSTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GID (location_type l)
      {
        return symbol_type (token::GID, std::move (l));
      }
#else
      static
      symbol_type
      make_GID (const location_type& l)
      {
        return symbol_type (token::GID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GROUP (location_type l)
      {
        return symbol_type (token::GROUP, std::move (l));
      }
#else
      static
      symbol_type
      make_GROUP (const location_type& l)
      {
        return symbol_type (token::GROUP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ILNAME (location_type l)
      {
        return symbol_type (token::ILNAME, std::move (l));
      }
#else
      static
      symbol_type
      make_ILNAME (const location_type& l)
      {
        return symbol_type (token::ILNAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INAME (location_type l)
      {
        return symbol_type (token::INAME, std::move (l));
      }
#else
      static
      symbol_type
      make_INAME (const location_type& l)
      {
        return symbol_type (token::INAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INUM (location_type l)
      {
        return symbol_type (token::INUM, std::move (l));
      }
#else
      static
      symbol_type
      make_INUM (const location_type& l)
      {
        return symbol_type (token::INUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IPATH (location_type l)
      {
        return symbol_type (token::IPATH, std::move (l));
      }
#else
      static
      symbol_type
      make_IPATH (const location_type& l)
      {
        return symbol_type (token::IPATH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IREGEX (location_type l)
      {
        return symbol_type (token::IREGEX, std::move (l));
      }
#else
      static
      symbol_type
      make_IREGEX (const location_type& l)
      {
        return symbol_type (token::IREGEX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IWHOLENAME (location_type l)
      {
        return symbol_type (token::IWHOLENAME, std::move (l));
      }
#else
      static
      symbol_type
      make_IWHOLENAME (const location_type& l)
      {
        return symbol_type (token::IWHOLENAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LINKS (location_type l)
      {
        return symbol_type (token::LINKS, std::move (l));
      }
#else
      static
      symbol_type
      make_LINKS (const location_type& l)
      {
        return symbol_type (token::LINKS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LNAME (location_type l)
      {
        return symbol_type (token::LNAME, std::move (l));
      }
#else
      static
      symbol_type
      make_LNAME (const location_type& l)
      {
        return symbol_type (token::LNAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MMIN (location_type l)
      {
        return symbol_type (token::MMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_MMIN (const location_type& l)
      {
        return symbol_type (token::MMIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MTIME (location_type l)
      {
        return symbol_type (token::MTIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MTIME (const location_type& l)
      {
        return symbol_type (token::MTIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (location_type l)
      {
        return symbol_type (token::NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const location_type& l)
      {
        return symbol_type (token::NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWER (location_type l)
      {
        return symbol_type (token::NEWER, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWER (const location_type& l)
      {
        return symbol_type (token::NEWER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWERXY (location_type l)
      {
        return symbol_type (token::NEWERXY, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWERXY (const location_type& l)
      {
        return symbol_type (token::NEWERXY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOGROUP (location_type l)
      {
        return symbol_type (token::NOGROUP, std::move (l));
      }
#else
      static
      symbol_type
      make_NOGROUP (const location_type& l)
      {
        return symbol_type (token::NOGROUP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOUSER (location_type l)
      {
        return symbol_type (token::NOUSER, std::move (l));
      }
#else
      static
      symbol_type
      make_NOUSER (const location_type& l)
      {
        return symbol_type (token::NOUSER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH (location_type l)
      {
        return symbol_type (token::PATH, std::move (l));
      }
#else
      static
      symbol_type
      make_PATH (const location_type& l)
      {
        return symbol_type (token::PATH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERM (location_type l)
      {
        return symbol_type (token::PERM, std::move (l));
      }
#else
      static
      symbol_type
      make_PERM (const location_type& l)
      {
        return symbol_type (token::PERM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READABLE (location_type l)
      {
        return symbol_type (token::READABLE, std::move (l));
      }
#else
      static
      symbol_type
      make_READABLE (const location_type& l)
      {
        return symbol_type (token::READABLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGEX (location_type l)
      {
        return symbol_type (token::REGEX, std::move (l));
      }
#else
      static
      symbol_type
      make_REGEX (const location_type& l)
      {
        return symbol_type (token::REGEX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SAMEFILE (location_type l)
      {
        return symbol_type (token::SAMEFILE, std::move (l));
      }
#else
      static
      symbol_type
      make_SAMEFILE (const location_type& l)
      {
        return symbol_type (token::SAMEFILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (location_type l)
      {
        return symbol_type (token::SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const location_type& l)
      {
        return symbol_type (token::SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (location_type l)
      {
        return symbol_type (token::TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const location_type& l)
      {
        return symbol_type (token::TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UID (location_type l)
      {
        return symbol_type (token::UID, std::move (l));
      }
#else
      static
      symbol_type
      make_UID (const location_type& l)
      {
        return symbol_type (token::UID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USED (location_type l)
      {
        return symbol_type (token::USED, std::move (l));
      }
#else
      static
      symbol_type
      make_USED (const location_type& l)
      {
        return symbol_type (token::USED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER (location_type l)
      {
        return symbol_type (token::USER, std::move (l));
      }
#else
      static
      symbol_type
      make_USER (const location_type& l)
      {
        return symbol_type (token::USER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHOLENAME (location_type l)
      {
        return symbol_type (token::WHOLENAME, std::move (l));
      }
#else
      static
      symbol_type
      make_WHOLENAME (const location_type& l)
      {
        return symbol_type (token::WHOLENAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WRITABLE (location_type l)
      {
        return symbol_type (token::WRITABLE, std::move (l));
      }
#else
      static
      symbol_type
      make_WRITABLE (const location_type& l)
      {
        return symbol_type (token::WRITABLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XTYPE (location_type l)
      {
        return symbol_type (token::XTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_XTYPE (const location_type& l)
      {
        return symbol_type (token::XTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (location_type l)
      {
        return symbol_type (token::DELETE, std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const location_type& l)
      {
        return symbol_type (token::DELETE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXEC (location_type l)
      {
        return symbol_type (token::EXEC, std::move (l));
      }
#else
      static
      symbol_type
      make_EXEC (const location_type& l)
      {
        return symbol_type (token::EXEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXECDIR (location_type l)
      {
        return symbol_type (token::EXECDIR, std::move (l));
      }
#else
      static
      symbol_type
      make_EXECDIR (const location_type& l)
      {
        return symbol_type (token::EXECDIR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLS (location_type l)
      {
        return symbol_type (token::FLS, std::move (l));
      }
#else
      static
      symbol_type
      make_FLS (const location_type& l)
      {
        return symbol_type (token::FLS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FPRINT (location_type l)
      {
        return symbol_type (token::FPRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_FPRINT (const location_type& l)
      {
        return symbol_type (token::FPRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FPRINT0 (location_type l)
      {
        return symbol_type (token::FPRINT0, std::move (l));
      }
#else
      static
      symbol_type
      make_FPRINT0 (const location_type& l)
      {
        return symbol_type (token::FPRINT0, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FPRINTF (location_type l)
      {
        return symbol_type (token::FPRINTF, std::move (l));
      }
#else
      static
      symbol_type
      make_FPRINTF (const location_type& l)
      {
        return symbol_type (token::FPRINTF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LS (location_type l)
      {
        return symbol_type (token::LS, std::move (l));
      }
#else
      static
      symbol_type
      make_LS (const location_type& l)
      {
        return symbol_type (token::LS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OK (location_type l)
      {
        return symbol_type (token::OK, std::move (l));
      }
#else
      static
      symbol_type
      make_OK (const location_type& l)
      {
        return symbol_type (token::OK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OKDIR (location_type l)
      {
        return symbol_type (token::OKDIR, std::move (l));
      }
#else
      static
      symbol_type
      make_OKDIR (const location_type& l)
      {
        return symbol_type (token::OKDIR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT0 (location_type l)
      {
        return symbol_type (token::PRINT0, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT0 (const location_type& l)
      {
        return symbol_type (token::PRINT0, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTF (location_type l)
      {
        return symbol_type (token::PRINTF, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTF (const location_type& l)
      {
        return symbol_type (token::PRINTF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRUNE (location_type l)
      {
        return symbol_type (token::PRUNE, std::move (l));
      }
#else
      static
      symbol_type
      make_PRUNE (const location_type& l)
      {
        return symbol_type (token::PRUNE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUIT (location_type l)
      {
        return symbol_type (token::QUIT, std::move (l));
      }
#else
      static
      symbol_type
      make_QUIT (const location_type& l)
      {
        return symbol_type (token::QUIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEPTH (location_type l)
      {
        return symbol_type (token::DEPTH, std::move (l));
      }
#else
      static
      symbol_type
      make_DEPTH (const location_type& l)
      {
        return symbol_type (token::DEPTH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILES0_FROM (location_type l)
      {
        return symbol_type (token::FILES0_FROM, std::move (l));
      }
#else
      static
      symbol_type
      make_FILES0_FROM (const location_type& l)
      {
        return symbol_type (token::FILES0_FROM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HELP (location_type l)
      {
        return symbol_type (token::HELP, std::move (l));
      }
#else
      static
      symbol_type
      make_HELP (const location_type& l)
      {
        return symbol_type (token::HELP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IGNORE_READDIR_RACE (location_type l)
      {
        return symbol_type (token::IGNORE_READDIR_RACE, std::move (l));
      }
#else
      static
      symbol_type
      make_IGNORE_READDIR_RACE (const location_type& l)
      {
        return symbol_type (token::IGNORE_READDIR_RACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAXDEPTH (location_type l)
      {
        return symbol_type (token::MAXDEPTH, std::move (l));
      }
#else
      static
      symbol_type
      make_MAXDEPTH (const location_type& l)
      {
        return symbol_type (token::MAXDEPTH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINDEPTH (location_type l)
      {
        return symbol_type (token::MINDEPTH, std::move (l));
      }
#else
      static
      symbol_type
      make_MINDEPTH (const location_type& l)
      {
        return symbol_type (token::MINDEPTH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOUNT (location_type l)
      {
        return symbol_type (token::MOUNT, std::move (l));
      }
#else
      static
      symbol_type
      make_MOUNT (const location_type& l)
      {
        return symbol_type (token::MOUNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOIGNORE_READDIR_RACE (location_type l)
      {
        return symbol_type (token::NOIGNORE_READDIR_RACE, std::move (l));
      }
#else
      static
      symbol_type
      make_NOIGNORE_READDIR_RACE (const location_type& l)
      {
        return symbol_type (token::NOIGNORE_READDIR_RACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOLEAF (location_type l)
      {
        return symbol_type (token::NOLEAF, std::move (l));
      }
#else
      static
      symbol_type
      make_NOLEAF (const location_type& l)
      {
        return symbol_type (token::NOLEAF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XDEV (location_type l)
      {
        return symbol_type (token::XDEV, std::move (l));
      }
#else
      static
      symbol_type
      make_XDEV (const location_type& l)
      {
        return symbol_type (token::XDEV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAYSTART (location_type l)
      {
        return symbol_type (token::DAYSTART, std::move (l));
      }
#else
      static
      symbol_type
      make_DAYSTART (const location_type& l)
      {
        return symbol_type (token::DAYSTART, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOLLOW (location_type l)
      {
        return symbol_type (token::FOLLOW, std::move (l));
      }
#else
      static
      symbol_type
      make_FOLLOW (const location_type& l)
      {
        return symbol_type (token::FOLLOW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOWARN (location_type l)
      {
        return symbol_type (token::NOWARN, std::move (l));
      }
#else
      static
      symbol_type
      make_NOWARN (const location_type& l)
      {
        return symbol_type (token::NOWARN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGEXTYPE (location_type l)
      {
        return symbol_type (token::REGEXTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_REGEXTYPE (const location_type& l)
      {
        return symbol_type (token::REGEXTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WARN (location_type l)
      {
        return symbol_type (token::WARN, std::move (l));
      }
#else
      static
      symbol_type
      make_WARN (const location_type& l)
      {
        return symbol_type (token::WARN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PAREN (location_type l)
      {
        return symbol_type (token::LEFT_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_PAREN (const location_type& l)
      {
        return symbol_type (token::LEFT_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PAREN (location_type l)
      {
        return symbol_type (token::RIGHT_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_PAREN (const location_type& l)
      {
        return symbol_type (token::RIGHT_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_ARG (NumberArg v, location_type l)
      {
        return symbol_type (token::NUMBER_ARG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_ARG (const NumberArg& v, const location_type& l)
      {
        return symbol_type (token::NUMBER_ARG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_ARG (string v, location_type l)
      {
        return symbol_type (token::STRING_ARG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_ARG (const string& v, const location_type& l)
      {
        return symbol_type (token::STRING_ARG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXEC_ARG (vector<string> v, location_type l)
      {
        return symbol_type (token::EXEC_ARG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXEC_ARG (const vector<string>& v, const location_type& l)
      {
        return symbol_type (token::EXEC_ARG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_POINT (string v, location_type l)
      {
        return symbol_type (token::START_POINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_START_POINT (const string& v, const location_type& l)
      {
        return symbol_type (token::START_POINT, v, l);
      }
#endif


    class context
    {
    public:
      context (const FindqParser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const FindqParser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    FindqParser (const FindqParser&);
    /// Non copyable.
    FindqParser& operator= (const FindqParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Report a syntax error
    /// \param yyctx     the context in which the error occurred.
    void report_syntax_error (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
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
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

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
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 393,     ///< Last index in yytable_.
      yynnts_ = 17,  ///< Number of nonterminal symbols.
      yyfinal_ = 91 ///< Termination state number.
    };


    // User arguments.
    function<FindqParser::symbol_type(LexParam&)> yylex;
    BisonParam& bisonParam;
    LexParam& lexParam;

  };

  inline
  FindqParser::symbol_kind_type
  FindqParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  FindqParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.copy< AndExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmd: // cmd
        value.copy< Cmd > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.copy< CommaExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_findq: // findq
        value.copy< Findq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.copy< NumberArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.copy< OrExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.copy< Primary > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_term: // term
        value.copy< Term > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.copy< Unit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.copy< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cmds: // cmds
        value.copy< vector<Cmd> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.copy< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  FindqParser::symbol_kind_type
  FindqParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  FindqParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  FindqParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_and_expr: // and_expr
        value.move< AndExpr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cmd: // cmd
        value.move< Cmd > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_comma_expr: // comma_expr
        value.move< CommaExpr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_findq: // findq
        value.move< Findq > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER_ARG: // NUMBER_ARG
        value.move< NumberArg > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_or_expr: // or_expr
        value.move< OrExpr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_primary: // primary
      case symbol_kind::S_test: // test
      case symbol_kind::S_action: // action
      case symbol_kind::S_global_opt: // global_opt
      case symbol_kind::S_positional_opt: // positional_opt
        value.move< Primary > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_term: // term
        value.move< Term > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_unit: // unit
        value.move< Unit > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING_ARG: // STRING_ARG
      case symbol_kind::S_START_POINT: // START_POINT
        value.move< string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cmds: // cmds
        value.move< vector<Cmd> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_EXEC_ARG: // EXEC_ARG
        value.move< vector<string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  FindqParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  FindqParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  FindqParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  FindqParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  FindqParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  FindqParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  FindqParser::symbol_kind_type
  FindqParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  FindqParser::symbol_kind_type
  FindqParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 164 "./src/grammar/findq_parser.bison.y"
} // findqparser
#line 3198 "findq_parser.bison.h"


// "%code provides" blocks.
#line 193 "./src/grammar/findq_parser.bison.y"

// %code provides codeblock
// goes in .h after namespace and parser class
// everything here needs FindqParser defined earlier

#ifdef _MSC_VER
#pragma warning(pop)
#endif

// parser objects
namespace findqparser {

using namespace std;

}


#line 3220 "findq_parser.bison.h"


#endif // !YY_YY_FINDQ_PARSER_BISON_H_INCLUDED
