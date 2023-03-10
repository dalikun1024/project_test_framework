#include "sum_integers.h"

#include "unity.h"   

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void Sum_of_integers_for_a_short_vector(void) {
  int integers[] = {1, 2, 3, 4, 5};
  TEST_ASSERT(sum_integers(integers, sizeof(integers)/sizeof(int)) == 1);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(Sum_of_integers_for_a_short_vector);
    return UNITY_END();
}
