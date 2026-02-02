#include "CUnit/CUError.h"
#include "CUnit/TestDB.h"
#include "solution.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_findMaxConsecutiveOnes_case1(void) {
  int nums[] = {1, 1, 0, 1, 1, 1};
  CU_ASSERT(findMaxConsecutiveOnes(nums, sizeof(nums) / sizeof(nums[0])) == 3);
}

void test_findMaxConsecutiveOnes_case2(void) {
  int nums[] = {1, 0, 1, 1, 0, 1};
  CU_ASSERT(findMaxConsecutiveOnes(nums, sizeof(nums) / sizeof(nums[0])) == 2);
}

int main(void) {
  CU_pSuite suite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  suite = CU_add_suite("FindMaxConsecutiveOnesTestSuite", 0, 0);
  if (suite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite, "findMaxConsecutiveOnes.case#1", test_findMaxConsecutiveOnes_case1)) ||
      (NULL == CU_add_test(suite, "findMaxConsecutiveOnes.case#2", test_findMaxConsecutiveOnes_case2))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
