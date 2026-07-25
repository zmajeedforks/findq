#ifndef FINDQ_PRIMARY_H
#define FINDQ_PRIMARY_H
// ast/findq_primary.h

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

#include "findq_token_types.h"

namespace findqparser {
using namespace std;

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
struct TestTag {};
struct ActionTag {};
struct GlobalOptTag {};
struct PositionalOptTag {};

// Prop has type like string, vector<string>, int
// has unique name, this could be an empty struct tag to make prop a unique type for variant inclusion
// is specific type of primary - test, action, global option, positional option, this is to insure a specific prop is only used as the intended primary
template <typename T, FixedString PropName, typename PrimaryTag>
struct Prop: T {
  using T::T;
  using T::operator=;

// honestly ridiculous to have to explicitly default all these constructors and operators
// if Prop derives from string it should behave exactly like string by default plus some

  constexpr Prop(const T& base): T(base) {}
  constexpr Prop(T&& base): T(move(base)) {}

  Prop(const Prop&) = default;
  Prop(Prop&&) = default;

  Prop& operator=(const Prop&) = default;
  Prop& operator=(Prop&&) = default;

  static constexpr string_view name = PropName;
  using type = T;

// to allow direct comparison of variant and Prop without using get<Name>(v) == Name{"abc"}
// compare variant == prop
  template <typename... VariantTypes>
    friend constexpr bool operator==(const variant<VariantTypes...>& var, const Prop& prop) {
      if (!holds_alternative<Prop>(var)) {
        return false;
      }
      return get<Prop>(var) == static_cast<const T&>(prop);
    }

// compare prop == variant
  template <typename... VariantTypes>
    friend constexpr bool operator==(const Prop& prop, const variant<VariantTypes...>& var) {
      return var == prop;
    }

// allow Prop to be initialized from simple pod structs
// is_constructible rquired to prevent clang from trying stupid combinations like AndExpr and uint64_t in NumberArg
  template <typename... Args>
    requires is_constructible_v<T, Args...>
    constexpr Prop(Args&&... args): T{forward<Args>(args)...} {}

};

// Prop specialization for int because it's not a class type
// provide conversion operators to act like int
// could also add c++26 custom static cast operators if needed for testing
template <FixedString PropName, typename PrimaryTag>
struct Prop<uint64_t, PropName, PrimaryTag> {
  uint64_t value;

  operator uint64_t&() { return value; }
  operator uint64_t() const { return value; }

  static constexpr string_view name = PropName;
  using type = uint64_t;
};

// test primaries

using Amin = Prop<NumberArg, "amin", TestTag>;
using Anewer = Prop<string, "anewer", TestTag>;
using Atime = Prop<NumberArg, "atime", TestTag>;
using Cmin = Prop<NumberArg, "cmin", TestTag>;
using Cnewer = Prop<string, "cnewer", TestTag>;
using Ctime = Prop<NumberArg, "ctime", TestTag>;
using Empty = Prop<monostate, "empty", TestTag>;
using Executable = Prop<monostate, "executable", TestTag>;
using False = Prop<monostate, "false", TestTag>;
using Fstype = Prop<string, "fstype", TestTag>;
using Gid = Prop<NumberArg, "gid", TestTag>;
using Group = Prop<string, "group", TestTag>;
using Ilname = Prop<string, "ilname", TestTag>;
using Iname = Prop<string, "iname", TestTag>;
using Inum = Prop<NumberArg, "inum", TestTag>;
using Ipath = Prop<string, "ipath", TestTag>;
using Iregex = Prop<string, "iregex", TestTag>;
using Iwholename = Prop<string, "iwholename", TestTag>;
using Links = Prop<NumberArg, "links", TestTag>;
using Lname = Prop<string, "lname", TestTag>;
using Mmin = Prop<NumberArg, "mmin", TestTag>;
using Mtime = Prop<NumberArg, "mtime", TestTag>;
using Name = Prop<string, "name", TestTag>;
using Newer = Prop<string, "newer", TestTag>;
using NewerXY = Prop<string, "newerXY", TestTag>;
using NoGroup = Prop<monostate, "nogroup", TestTag>;
using NoUser = Prop<monostate, "nouser", TestTag>;
using Path = Prop<string, "path", TestTag>;
using Perm = Prop<string, "perm", TestTag>;
using Readable = Prop<monostate, "readable", TestTag>;
using Regex = Prop<string, "regex", TestTag>;
using Samefile = Prop<monostate, "samefile", TestTag>;
using Size = Prop<NumberArg, "size", TestTag>;
using True = Prop<monostate, "true", TestTag>;
using Type = Prop<string, "type", TestTag>;
using Uid = Prop<NumberArg, "uid", TestTag>;
using Used = Prop<NumberArg, "used", TestTag>;
using User = Prop<string, "user", TestTag>;
using Wholename = Prop<string, "wholename", TestTag>;
using Writable = Prop<monostate, "writable", TestTag>;
using Xtype = Prop<string, "xtype", TestTag>;


using TestPrimary = variant<Amin, Anewer, Atime, Cmin, Cnewer, Ctime, Empty, Executable, False, Fstype, Gid, Group, Ilname, Iname, Inum, Ipath, Iregex, Iwholename, Links, Lname, Mmin, Mtime, Name, Newer, NewerXY, NoGroup, NoUser, Path, Perm, Readable, Regex, Samefile, Size, True, Type, Uid, User, Used, Wholename, Writable, Xtype>;

// action primaries

using Delete = Prop<monostate, "delete", ActionTag>;
using Exec = Prop<vector<string>, "exec", ActionTag>;
using Execdir = Prop<vector<string>, "execdir", ActionTag>;
using Fls = Prop<string, "fls", ActionTag>;
using Fprint = Prop<string, "fprint", ActionTag>;
using Fprint0 = Prop<string, "fprint0", ActionTag>;
using Fprintf = Prop<string, "fprintf", ActionTag>;
using Ls = Prop<monostate, "ls", ActionTag>;
using Ok = Prop<vector<string>, "ok", ActionTag>;
using Okdir = Prop<vector<string>, "okdir", ActionTag>;
using Print = Prop<monostate, "print", ActionTag>;
using Print0 = Prop<monostate, "print0", ActionTag>;
using Printf = Prop<string, "printf", ActionTag>;
using Prune = Prop<monostate, "prune", ActionTag>;
using Quit = Prop<monostate, "quit", ActionTag>;

#if 0
using ActionPrimary = variant<Delete, Exec, Execdir, Fls, Fprint, Fprint0, Fprintf, Ls, Ok, Okdir, Print, Print0, Printf, Prune, Quit>;
#else
using ActionPrimary = variant<Exec, Ls, Printf>;
#endif

// global option primaries

using Depth = Prop<monostate, "depth", GlobalOptTag>;
using Files0From = Prop<string, "files0-from", GlobalOptTag>;
using Help = Prop<monostate, "help", GlobalOptTag>;
using IgnoreReaddirRace = Prop<monostate, "ignore_readdir_race", GlobalOptTag>;
using Maxdepth = Prop<NumberArg, "maxdepth", GlobalOptTag>;
using Mindepth = Prop<NumberArg, "mindepth", GlobalOptTag>;
using Mount = Prop<monostate, "mount", GlobalOptTag>;
using NoIgnoreReaddirRace = Prop<monostate, "noignore_readdir_race", GlobalOptTag>;
using NoLeaf = Prop<monostate, "noleaf", GlobalOptTag>;
using Xdev = Prop<monostate, "xdev", GlobalOptTag>;

using GlobalOptPrimary = variant<Depth, Files0From, Help, IgnoreReaddirRace, Maxdepth, Mindepth, Mount, NoIgnoreReaddirRace, NoLeaf, Xdev>;

// positional option primaries

using Daystart = Prop<monostate, "daystart", PositionalOptTag>;
using Follow = Prop<monostate, "follow", PositionalOptTag>;
using NoWarn = Prop<monostate, "nowarn", PositionalOptTag>;
using Regextype = Prop<string, "regextype", PositionalOptTag>;
using Warn = Prop<monostate, "warn", PositionalOptTag>;

using PositionalOptPrimary = variant<Daystart, Follow, NoWarn, Regextype, Warn>;



// flatten multiple nested variants into single variant

// seems to cause vc++ bug with error c2672 no matching overload found if even one subtype in merged variant is missing in overload despite containing fallback default lambda
// generally a problem only during initial development when it might be fine to skip some subtypes
// might get rid of MergeVariants and simply have Primary: variant<TestPrimary, ActionPrimary, GlobalOptPrimary, PositionalOptPrimary>
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





}

namespace std {

// print formatters for primary types that inherit string or vector<string>
// restrict formatter to our special primary types above with name field

// string_view avoids string copy
// without this, string primaries like Name print as array of characters
  template <typename T>
    requires is_base_of_v<string, T> && requires { T::name; }
  struct formatter<T, char> : formatter<string_view, char> {
    using formatter<string_view, char>::format;
  };

// without this print({}) won't compile for vector<string> primaries
  template <typename T>
    requires is_base_of_v<vector<string>, T> && requires { T::name; }
    struct formatter<T, char> : formatter<vector<string>, char> {
      using formatter<vector<string>, char>::format;
    };

}

#endif

