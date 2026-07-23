// findq_ast.gtest.cpp

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

#include "findq_ast.h"

#include <sstream>
#include <string>
#include <variant>
#include <utility>
#include <print>

#include <gtest/gtest.h>

using namespace std;

namespace findqparser::testing {

TEST(TestPrimary, test_000) {

  TestPrimary p = Name{"*.cpp"};

  EXPECT_EQ(get<Name>(p), "*.cpp");

}

TEST(TestPrimary, test_001) {

  TestPrimary p = Size{123};

  EXPECT_EQ(get<Size>(p), 123);

}

TEST(TestPrimary, test_002) {

  TestPrimary p = Empty{};

  EXPECT_EQ(get<Empty>(p), monostate{});

}

TEST(ActionPrimary, test_003) {

  ActionPrimary p = Ls{};

  EXPECT_EQ(get<Ls>(p), monostate{});

}

TEST(ActionPrimary, test_004) {

  ActionPrimary p = Exec{"ls", "-l"};

  EXPECT_EQ(get<Exec>(p), (vector{"ls"s, "-l"s}));

}

TEST(ActionPrimary, test_005) {

  ActionPrimary p = Printf{"%p %s %t"};

  EXPECT_EQ(get<Printf>(p), "%p %s %t");

}

TEST(Primary, test_006) {

  Primary p = Name{"*.cpp"};

  EXPECT_EQ(get<Name>(p), "*.cpp");

}

TEST(Primary, test_007) {

  Primary p = Size{123};

  EXPECT_EQ(get<Size>(p), 123);

}

TEST(Primary, test_008) {

  Primary p = Empty{};

  EXPECT_EQ(get<Empty>(p), monostate{});

}

TEST(Primary, test_009) {

  Primary p = Exec{"ls", "-l"};

  EXPECT_EQ(get<Exec>(p), (vector{"ls"s, "-l"s}));

}

TEST(Primary, test_010) {

  Primary p = Printf{"%p %s %t"};

  EXPECT_EQ(get<Printf>(p), "%p %s %t");

}

TEST(Ast, test_001) {

  Unit expr = Primary{ Name{ "file.txt" } };
  EXPECT_EQ(get<Name>(get<Primary>(expr)), "file.txt");
}

TEST(Ast, test_002) {

  Unit expr = { Name{ "file.txt" } };
  EXPECT_EQ(get<Name>(get<Primary>(expr)), "file.txt");
}

TEST(Ast, test_003) {

  Item expr = { { Name{ "file.txt" } } };
  EXPECT_EQ(get<Name>(get<Primary>(expr.unit)), "file.txt");
  EXPECT_TRUE(expr.isTrue);
}

TEST(Ast, test_004) {

  Item expr = { { Name{ "file.txt" } }, false };
  EXPECT_EQ(get<Name>(get<Primary>(expr.unit)), "file.txt");
  EXPECT_FALSE(expr.isTrue);
}

TEST(Ast, test_005) {

  AndExpr expr = {{ { { Name{ "file.txt" } } } }};
  EXPECT_EQ(get<Name>(get<Primary>(expr.ands[0].unit)), "file.txt");
  EXPECT_TRUE(expr.ands[0].isTrue);
}

TEST(Ast, test_006) {

  AndExpr expr = {{ { { Uid{ 123 } } } }};
  EXPECT_EQ(get<Uid>(get<Primary>(expr.ands[0].unit)), 123);
  EXPECT_TRUE(expr.ands[0].isTrue);
}

TEST(Ast, test_007) {

  OrExpr expr = {{
    AndExpr{{
      { { Name{ "file.txt" } } }
    }},

    AndExpr{{
      { { User{ "joe" } } }
    }},
  }};

  EXPECT_EQ(get<Name>(get<Primary>(expr.ors[0].ands[0].unit)), "file.txt");
  EXPECT_EQ(get<User>(get<Primary>(expr.ors[1].ands[0].unit)), "joe");
}

TEST(Ast, test_008) {

  OrExpr expr = {{
    AndExpr{{
      { { Name{ "file.txt" } } },
      { { Empty{} }, false }
    }},

    AndExpr{{
      { { Uid{ 123 } } }
    }},
  }};

  EXPECT_EQ(get<Name>(get<Primary>(expr.ors[0].ands[0].unit)), "file.txt");
  EXPECT_EQ(get<Empty>(get<Primary>(expr.ors[0].ands[1].unit)), (monostate{}));
  EXPECT_FALSE(expr.ors[0].ands[1].isTrue);
  EXPECT_EQ(get<Uid>(get<Primary>(expr.ors[1].ands[0].unit)), 123);
}

TEST(Ast, test_009) {

  CommaExpr expr = {{
    OrExpr{{
      AndExpr{{
        { { Name{ "file.txt" } } },
        { { Empty{} }, false }
      }},

      AndExpr{{
        { { Uid{ 123 } } }
      }},
    }}
  }};

  EXPECT_EQ(get<Name>(get<Primary>(expr.segs[0].ors[0].ands[0].unit)), "file.txt");
  EXPECT_EQ(get<Empty>(get<Primary>(expr.segs[0].ors[0].ands[1].unit)), (monostate{}));
  EXPECT_FALSE(expr.segs[0].ors[0].ands[1].isTrue);
  EXPECT_EQ(get<Uid>(get<Primary>(expr.segs[0].ors[1].ands[0].unit)), 123);

}

TEST(AstNode, test_000) {

  Cmd expr = {
    { "/opt" },
    {
      CommaExpr{{
        OrExpr{{
          AndExpr{{
            { { Name{ "file.txt" } } },
            { { Empty{} }, false }
          }},

          AndExpr{{
            { { Uid{ 123 } } }
          }},
        }}
      }}
    }
  };

  EXPECT_EQ(expr.starts[0], "/opt");
  EXPECT_EQ(get<Name>(get<Primary>(expr.exprs[0].segs[0].ors[0].ands[0].unit)), "file.txt");
  EXPECT_EQ(get<Empty>(get<Primary>(expr.exprs[0].segs[0].ors[0].ands[1].unit)), (monostate{}));
  EXPECT_FALSE(expr.exprs[0].segs[0].ors[0].ands[1].isTrue);
  EXPECT_EQ(get<Uid>(get<Primary>(expr.exprs[0].segs[0].ors[1].ands[0].unit)), 123);

  FindqAstNode{expr}.printAst();
}


}

