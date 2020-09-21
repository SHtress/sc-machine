/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "catch2/catch.hpp"
#include "sc-test-framework/sc_test_unit.hpp"
#include "test_scs_utils.hpp"

TEST_CASE("scs_level_4", "[test scs level 4]")
{
  test::ScTestUnit::InitMemory("sc-memory.ini", "");
  ScMemoryContext ctx(sc_access_lvl_make_min, "scs_level_4");

  SECTION("simple_1")
  {
    SUBTEST_START("simple_1")
    {
      try
      {
        char const * data = "a -> b: c; d;;";

        scs::Parser parser;
        REQUIRE(parser.Parse(data));

        TripleTester tester(parser);
        tester({
                     {
                           { ScType::NodeConst, "a" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::NodeConst,              "c" }
                     },
                     {
                           { ScType::NodeConst, "b" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local }
                     },
                     {
                           { ScType::NodeConst, "a" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::NodeConst,              "d" }
                     },
                     {
                           { ScType::NodeConst, "b" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local }
                     }
               });

        auto const & triples = parser.GetParsedTriples();

        REQUIRE(triples.size() == 4);
        REQUIRE(triples[1].m_target == triples[0].m_edge);
        REQUIRE(triples[3].m_target == triples[2].m_edge);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"simple_1\" failed");
      }
    }
    SUBTEST_END()
  }

  SECTION("simple_2")
  {
    SUBTEST_START("simple_2")
    {
      try
      {
        char const * data = "a -> b: c; <- d: e: f;;";

        scs::Parser parser;
        REQUIRE(parser.Parse(data));

        TripleTester tester(parser);
        tester({
                     {
                           { ScType::NodeConst, "a" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::NodeConst,              "c" }
                     },
                     {
                           { ScType::NodeConst, "b" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                     },
                     {
                           { ScType::NodeConst, "f" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::NodeConst,              "a" }
                     },
                     {
                           { ScType::NodeConst, "d" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                     },
                     {
                           { ScType::NodeConst, "e" },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                           { ScType::EdgeAccessConstPosPerm, scs::Visibility::Local },
                     }
               });

        auto const & triples = parser.GetParsedTriples();

        REQUIRE(triples.size() == 5);
        REQUIRE(triples[0].m_edge == triples[1].m_target);
        REQUIRE(triples[2].m_edge == triples[3].m_target);
        REQUIRE(triples[2].m_edge == triples[4].m_target);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"simple_2\" failed");
      }
    }
    SUBTEST_END()
  }

  ctx.Destroy();
  test::ScTestUnit::ShutdownMemory(false);
}
