#include <catch2/catch_all.hpp>

#include <v3d.hpp>
using namespace V3D;

inline real_t rand_real()
{
  return GENERATE(-10.0, 10.0);
}

inline int rand_int()
{
  return GENERATE(-10, 10);
}

TEST_CASE("MathTypes")
{
  SECTION("Vec2")
  {
    Vec2 test_1 = {rand_real(), rand_real()};
    Vec2 test_2 = test_1;
    Vec2 test_3 = {
      test_1.x + 255, 
      test_1.y - 255
    };

    REQUIRE(test_1 == test_2);
    REQUIRE_FALSE(test_3 == test_1);
    REQUIRE_FALSE(test_3 == test_2);
  }

  SECTION("iVec2")
  {
    iVec2 test_1 = {rand_int(), rand_int()};
    iVec2 test_2 = test_1;
    iVec2 test_3 = {
      test_1.x + 255, 
      test_1.y - 255
    };

    REQUIRE(test_1 == test_2);
    REQUIRE_FALSE(test_3 == test_1);
    REQUIRE_FALSE(test_3 == test_2);
  }

  SECTION("Size")
  {
    Size test_1 = {rand_real(), rand_real()};
    Size test_2 = test_1;
    Size test_3 = {
      test_1.width + 255, 
      test_1.height - 255
    };

    REQUIRE(test_1 == test_2);
    REQUIRE_FALSE(test_3 == test_1);
    REQUIRE_FALSE(test_3 == test_2);
  }

  SECTION("iSize")
  {
    iSize test_1 = {rand_int(), rand_int()};
    iSize test_2 = test_1;
    iSize test_3 = {
      test_1.width + 255, 
      test_1.height - 255
    };

    REQUIRE(test_1 == test_2);
    REQUIRE_FALSE(test_3 == test_1);
    REQUIRE_FALSE(test_3 == test_2);
  }
}