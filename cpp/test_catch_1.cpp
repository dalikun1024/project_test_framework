#include "sum_integers.hpp"

// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Sum of integers for a short vector", "[short]") {
  int integers[] = {1, 2, 3, 4, 5};
  REQUIRE(sum_integers(integers, sizeof(integers)/sizeof(int)) == 1);
}