#include "sum_integers.h"

#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void Sum_of_integers_for_a_longer_vector(void) {
  int integers[1000];
  for (int i = 1; i < 1001; ++i) {
    integers[i-1] = i;
  }
  TEST_ASSERT(sum_integers(integers, sizeof(integers)/sizeof(int)) == 500500);
}



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(Sum_of_integers_for_a_longer_vector);
    return UNITY_END();
}
