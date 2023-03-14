/*
 *  Simple example of a CUnit unit test.
 *
 *  compile with -lcunit :
 *  gcc -o fileA.tests cunit_fileA.c fileA_suite.c fileA.c -lcunit
 *
 *  the complete list of the CU_* can be found at
 *  http://cunit.sourceforge.net/doc/writing_tests.html#assertions
 */

/* use the basic interface */
#include "CUnit/Basic.h"

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */

int init_suite_fileA(void) {
/* 
 *   if (problem during initialisation)
 *     return -1; // this number can be used to explicit the problem
 */
  return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_fileA(void) {
/* 
 *   if (problem during cleaning)
 *     return -1; // this number can be used to explicit the problem
 */
  return 0;
}

int simpleDivision(int a, int b) {
  if (b == 0)
    return -1;

  if ((a < 0) || (b < 0))
    return -2;

  return a/b;
}

/* A test
 */
void testNormalValues(void) {
  /* classic cases */
  CU_ASSERT_EQUAL(simpleDivision(1, 1), 1);
  CU_ASSERT_EQUAL(simpleDivision(100, 10), 10);
  CU_ASSERT_EQUAL(simpleDivision(42, 6), 7);

  /* non integer result should be floored */
  CU_ASSERT_EQUAL(simpleDivision(5, 3), 1);
  CU_ASSERT_EQUAL(simpleDivision(14, 4), 3);
}

/* Another test
 */
void testErrorValues(void) {
  /* division by 0 should return -1 */
  CU_ASSERT_EQUAL(simpleDivision(1, 0), -1);
  CU_ASSERT_EQUAL(simpleDivision(427, 0), -1);

  /* strange cases */
  CU_ASSERT_EQUAL(simpleDivision(0, 0), -1);
  CU_ASSERT_EQUAL(simpleDivision(0, 1), 0);

  /* use of negative number should return -2 */
  CU_ASSERT_EQUAL(simpleDivision(-63, 39), -2);
  CU_ASSERT_EQUAL(simpleDivision(78, -36), -2);
  CU_ASSERT_EQUAL(simpleDivision(-43, -23), -3);
}

int main() {
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite fileA", init_suite_fileA, clean_suite_fileA);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  /* all the functions in fileA_suite.h must be added */
  if ((NULL == CU_add_test(pSuite,
          "test of simpleDivision() in classic cases", testNormalValues)) ||
     (NULL == CU_add_test(pSuite,
          "test of simpleDivision() in pathologic cases", testErrorValues))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}