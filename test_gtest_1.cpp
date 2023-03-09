#include "sum_integers.hpp"

#include "gtest/gtest.h"


TEST(FactorialTest, Negative) {
  int integers[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(sum_integers(integers, sizeof(integers)/sizeof(int)), 1);
}