#include "sum_integers.hpp"

// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Sum of integers for a longer vector", "[long]") {
  int integers[1000];
  for (int i = 1; i < 1001; ++i) {
    integers[i-1] = i;
  }
  REQUIRE(sum_integers(integers, sizeof(integers)/sizeof(int)) == 500500);
}
