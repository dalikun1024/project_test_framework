#include "sum_integers.hpp"

// this tells catch to provide a main()
// only do this in one cpp file
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "gtest/gtest.h"

TEST(FactorialTest, Positive) {
  int integers[1000];
  for (int i = 1; i < 1001; ++i) {
    integers[i-1] = i;
  }
  EXPECT_EQ(sum_integers(integers, sizeof(integers)/sizeof(int)), 500500);
}
