#ifndef FINDQ_AST_H
#define FINDQ_AST_H
// ast/findq_ast.h

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
#include <set>
#include <flat_set>
#include <initializer_list>
#include <map>
#include <variant>
#include <compare>
#include <utility>
#include <algorithm>
#include <memory>
#include <functional>
#include <print>

#include "findq_primary.h"

namespace findqparser {
using namespace std;

#if 0
// data structures for primaries - test, action, global option, positional option

// helper for string nontype template parameter
// remove if fixed_string becomes part of c++ standard 
template<size_t N>
struct FixedString {
  char buf[N];
  constexpr FixedString(const char (&str)[N]) { copy_n(str, N, buf); }
  constexpr operator string_view() const { return {buf, N - 1}; }
};

// the 4 kinds of primaries to use as PrimaryTag type
struct TestPrimaryTag {};
struct ActionPrimaryTag {};
#if 0
struct GlobalOptPrimary {};
struct PositionalOptPrimary {};
#endif

// global option primaries

// positional option primaries

// Prop has type like string, vector<string>, int
// has unique name, this could be an empty struct tag to make prop a unique type for variant inclusion
// is specific type of primary - test, action, global option, positional option, this is to insure a specific prop is only used as the intended primary
template <typename T, FixedString PropName, typename PrimaryTag>
struct Prop : T {
  using T::T;

  static constexpr string_view name = PropName;
  using type = T;
};

// Prop specialization for int because it's not a class type
// provide conversion operators to act like int
// could also add c++26 custom static cast operators if needed for testing
template <FixedString PropName, typename PrimaryTag>
struct Prop<int, PropName, PrimaryTag> {
  int value;

  operator int&() { return value; }
  operator int() const { return value; }

  static constexpr string_view name = PropName;
  using type = int;
};

// test primaries

using Amin = Prop<int, "amin", TestPrimaryTag>;
using Anewer = Prop<string, "anewer", TestPrimaryTag>;
using Atime = Prop<int, "atime", TestPrimaryTag>;
using Cmin = Prop<int, "cmin", TestPrimaryTag>;
using Cnewer = Prop<string, "cnewer", TestPrimaryTag>;
using Ctime = Prop<int, "ctime", TestPrimaryTag>;
using Empty = Prop<monostate, "empty", TestPrimaryTag>;
using Executable = Prop<monostate, "executable", TestPrimaryTag>;
using False = Prop<monostate, "false", TestPrimaryTag>;
using Iname = Prop<string, "iname", TestPrimaryTag>;
using Name = Prop<string, "name", TestPrimaryTag>;
using Path = Prop<string, "path", TestPrimaryTag>;
using Size = Prop<int, "size", TestPrimaryTag>;
using Type = Prop<string, "type", TestPrimaryTag>;
using Uid = Prop<int, "uid", TestPrimaryTag>;
using User = Prop<string, "user", TestPrimaryTag>;

#if 0
using TestPrimary = variant<Amin, Anewer, Atime, Cmin, Cnewer, Ctime, Empty, Executable, False, Iname, Name, Path, Size, Type, Uid, User>;
#else
using TestPrimary = variant<Empty, Name, Size, Uid, User>;
#endif

// action primaries

using Delete = Prop<monostate, "delete", ActionPrimaryTag>;
using Exec = Prop<vector<string>, "exec", ActionPrimaryTag>;
using Execdir = Prop<vector<string>, "execdir", ActionPrimaryTag>;
using Fls = Prop<string, "fls", ActionPrimaryTag>;
using Fprint = Prop<string, "fprint", ActionPrimaryTag>;
using Fprint0 = Prop<string, "fprint0", ActionPrimaryTag>;
using Fprintf = Prop<string, "fprintf", ActionPrimaryTag>;
using Ls = Prop<monostate, "ls", ActionPrimaryTag>;
using Ok = Prop<vector<string>, "ok", ActionPrimaryTag>;
using Okdir = Prop<vector<string>, "okdir", ActionPrimaryTag>;
using Print = Prop<monostate, "print", ActionPrimaryTag>;
using Print0 = Prop<monostate, "print0", ActionPrimaryTag>;
using Printf = Prop<string, "printf", ActionPrimaryTag>;
using Prune = Prop<monostate, "prune", ActionPrimaryTag>;
using Quit = Prop<monostate, "quit", ActionPrimaryTag>;

#if 0
using ActionPrimary = variant<Delete, Exec, Execdir, Fls, Fprint, Fprint0, Fprintf, Ls, Ok, Okdir, Print, Print0, Printf, Prune, Quit>;
#else
using ActionPrimary = variant<Exec, Ls, Printf>;
#endif

// main ast node types

// flatten multiple nested variants into single variant

// may cause vc++ bug with error c2672 no matching overload found if even one subtype in merged variant is missing in overload despite containing fallback default lambda
// generally only a problem during initial development when it might be fine to skip some subtypes
template<typename... Variants>
struct MergeVariants;

// MergeVariants recursive specialization to combine two or more variant types
// base case
template <typename... T1>
struct MergeVariants<variant<T1...>> {
  using type = variant<T1...>;
};

//recursive case
template <typename... T1, typename... T2, typename... Rest>
struct MergeVariants<variant<T1...>, variant<T2...>, Rest...> {
  using type = typename MergeVariants<variant<T1..., T2...>, Rest...>::type;
};

// flatten variants into single variant using MergeVariants helper
// note type at the end
using Primary = typename MergeVariants<TestPrimary, ActionPrimary>::type;

#endif

struct AndExpr;
struct Findq;
struct Cmd;
struct CommaExpr;
struct Group;
struct Item;
struct OrExpr;
struct Unit;

using StartPoint = string;

struct Findq {
  vector<Cmd> cmds;
};

struct Cmd {
  vector<StartPoint> starts;
  vector<CommaExpr> exprs;
};

struct CommaExpr {
  vector<OrExpr> segs;
};

struct OrExpr {
  vector<AndExpr> ors;
};

struct AndExpr {
  vector<Item> ands;
};

struct Group: public CommaExpr {
};

// Unit must follow its subtypes Primary, Group
// Unit could be typedef but clashes with Unit in googletest
struct Unit: variant<Primary, Group> {
  using variant::variant;
};

// Item must follow Unit
struct Item {
  Unit unit;
  bool isTrue = true;
};
struct FindqAstNode: variant<AndExpr, Findq, Cmd, CommaExpr, Item, OrExpr, Primary, Unit> {
  using variant::variant;

  void printAst() const;

private:

#if WIN32
  template<class... Ts> struct __declspec(empty_bases) overload: Ts... { using Ts::operator()...; };
#else
  template<class... Ts> struct overload: Ts... { using Ts::operator()...; };
#endif
  template<class... Ts> overload(Ts...) -> overload<Ts...>;

};

// definitions

inline
void FindqAstNode::printAst() const {

  visit(overload{

    [](this auto&& self, const Findq& f) -> void {
    println("find:");
      for(const auto& cmd: f.cmds) {
        self(cmd);
        println("\n");
      }
    },

    [](this auto&& self, const Cmd& c) -> void {
    println("cmd:");
      for(const auto& start: c.starts) {
      print("start: {}", start);
        println("\n");
      }
      for(const auto& expr: c.exprs) {
        self(expr);
        println("\n");
      }
    },

    [](this auto&& self, const CommaExpr& c) -> void {
    println("comma");
      for(const auto& seg: c.segs) {
        self(seg);
        println("\n");
      }
    },

    [](this auto&& self, const OrExpr& o) -> void {
    println("or:");
      for(const auto& ora: o.ors) {
        self(ora);
        println("\n");
      }
    },

    [](this auto&& self, const AndExpr& a) -> void {
    println("and:");
      for(const auto& item: a.ands) {
        self(item);
        println("\n");
      }
    },

    [](this auto&& self, const Item& i) -> void {
    println("item:");
      println("istrue {}", i.isTrue);
      self(i.unit);
    },

    [](this auto&& self, const Unit& u) -> void {
    println("unit:");
#if __cpp_lib_variant >= 202306L
      u.visit(self);
#else
      visit(self, u);
#endif
    },

    [](this auto&& self, const Primary& p) -> void {
    println("primary:");
#if __cpp_lib_variant >= 202306L
      p.visit(self);
#else
      visit(self, p);
#endif
    },

    [](this auto&&, const Name& n) -> void {
      //println("-name \"{}\"", string_view(n));
      println("-name \"{}\"", n);
    },

    [](this auto&&, const User& u) -> void {
      println("-user \"{}\"", u);
    },

    [](this auto&&, const Uid& u) -> void {
      println("-uid {}", u.value);
    },

    [](this auto&&, const Size& s) -> void {
      println("-size {}", s.value);
    },

    [](this auto&&, const Empty&) -> void {
      println("-empty");
    },

    [](this auto&&, const Exec&) -> void {
      println("-exec");
    },

    [](this auto&&, const Printf&) -> void {
      println("-printf");
    },

    [](this auto&&, const Ls&) -> void {
      println("-ls");
    },


// default match

    [](this const auto&&, const auto&) -> void {
      println("printAst.constrvalref: unexpected default match");
    },

// new c++26 variant visit member function, takes 1 parameter
// old variant visit global function, takes 2 parameters
#if __cpp_lib_variant >= 202306L
  });
#else
  }, *this);
#endif

}

}

#endif

