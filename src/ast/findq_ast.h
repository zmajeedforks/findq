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

// main ast node types

struct AndExpr;
struct Findq;
struct Cmd;
struct CommaExpr;
struct GroupExpr;
struct Term;
struct OrExpr;
struct Unit;

using StartPoint = string;

struct Findq {
  vector<Cmd> cmds;
};

struct CommaExpr {
  vector<OrExpr> segs;
};

struct Cmd {
  vector<StartPoint> starts;
  CommaExpr expr;
};

struct OrExpr {
  vector<AndExpr> ors;
};

struct AndExpr {
  vector<Term> ands;
};

struct GroupExpr: public CommaExpr {
};

// Unit must follow subtypes Primary, GroupExpr
// Unit could be typedef but clashes with Unit in googletest
struct Unit: variant<Primary, GroupExpr> {
  using variant::variant;
};

// Term must follow Unit
struct Term {
  Unit unit;
  bool isTrue = true;
};
struct FindqAstNode: variant<AndExpr, Findq, Cmd, CommaExpr, Term, OrExpr, Primary, Unit> {
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
      self(c.expr);
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
      for(const auto& term: a.ands) {
        self(term);
        println("\n");
      }
    },

    [](this auto&& self, const Term& i) -> void {
    println("term:");
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

    [](this auto&& self, const TestPrimary& t) -> void {
    println("test primary:");
#if __cpp_lib_variant >= 202306L
      t.visit(self);
#else
      visit(self, t);
#endif
    },

    [](this auto&& self, const ActionPrimary& a) -> void {
    println("test primary:");
#if __cpp_lib_variant >= 202306L
      a.visit(self);
#else
      visit(self, a);
#endif
    },


    [](this auto&&, const Amin&) -> void {
      println("-amin");
    },

    [](this auto&&, const Anewer&) -> void {
      println("-anewer");
    },

    [](this auto&&, const Atime&) -> void {
      println("-atime");
    },

    [](this auto&&, const Cmin&) -> void {
      println("-cmin");
    },

    [](this auto&&, const Cnewer&) -> void {
      println("-cnewer");
    },

    [](this auto&&, const Ctime&) -> void {
      println("-ctime");
    },

    [](this auto&&, const Empty&) -> void {
      println("-empty");
    },

    [](this auto&&, const Executable&) -> void {
      println("-executable");
    },

    [](this auto&&, const Fstype&) -> void {
      println("-fstype");
    },

    [](this auto&&, const Gid&) -> void {
      println("-gid");
    },

    [](this auto&&, const Group&) -> void {
      println("-group");
    },

    [](this auto&&, const Ilname&) -> void {
      println("-ilname");
    },

    [](this auto&&, const Iname&) -> void {
      println("-iname");
    },

    [](this auto&&, const Inum&) -> void {
      println("-inum");
    },

    [](this auto&&, const Ipath&) -> void {
      println("-ipath");
    },

    [](this auto&&, const Iregex&) -> void {
      println("-iregex");
    },

    [](this auto&&, const Iwholename&) -> void {
      println("-iwholename");
    },

    [](this auto&&, const Links&) -> void {
      println("-links");
    },

    [](this auto&&, const Lname&) -> void {
      println("-lname");
    },

    [](this auto&&, const Mmin&) -> void {
      println("-mmin");
    },

    [](this auto&&, const Mtime&) -> void {
      println("-mtime");
    },

    [](this auto&&, const Name& n) -> void {
      //println("-name \"{}\"", string_view(n));
      println("-name \"{}\"", n);
    },

    [](this auto&&, const Newer&) -> void {
      println("-newer");
    },

    [](this auto&&, const NewerXY&) -> void {
      println("-newerXY");
    },

    [](this auto&&, const NoGroup&) -> void {
      println("-nogroup");
    },

    [](this auto&&, const NoUser&) -> void {
      println("-nouser");
    },

    [](this auto&&, const Path&) -> void {
      println("-path");
    },

    [](this auto&&, const Perm&) -> void {
      println("-perm");
    },

    [](this auto&&, const Readable&) -> void {
      println("-readable");
    },

    [](this auto&&, const Regex&) -> void {
      println("-regex");
    },

    [](this auto&&, const Samefile&) -> void {
      println("-samefile");
    },

    [](this auto&&, const Size&) -> void {
      println("-size");
    },

    [](this auto&&, const True&) -> void {
      println("-true");
    },

    [](this auto&&, const Type&) -> void {
      println("-type");
    },

    [](this auto&&, const Uid&) -> void {
      println("-uid");
    },

    [](this auto&&, const Used&) -> void {
      println("-used");
    },

    [](this auto&&, const User& u) -> void {
      println("-user \"{}\"", u);
    },

    [](this auto&&, const Wholename&) -> void {
      println("-wholename");
    },

    [](this auto&&, const Writable&) -> void {
      println("-writable");
    },

    [](this auto&&, const Xtype&) -> void {
      println("-xtype");
    },



    [](this auto&&, const Exec&) -> void {
      println("-exec");
    },

    [](this auto&&, const False&) -> void {
      println("-false");
    },

    [](this auto&&, const Ls&) -> void {
      println("-ls");
    },

    [](this auto&&, const Printf&) -> void {
      println("-printf");
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

