#include "solution.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <string.h>

#define LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define EQUAL(leftArray, rightArray) (memcmp(leftArray, rightArray, sizeof(leftArray)) == 0)

void test_merge_case1(void) {
  int nums1[] = {1, 2, 3, 0, 0, 0};
  int nums2[] = {2, 5, 6};

  merge(nums1, LENGTH(nums1), 3, nums2, LENGTH(nums2), 3);

  CU_ASSERT_TRUE(EQUAL(nums1, ((int[]){1, 2, 2, 3, 5, 6})));
}

void test_merge_case2(void) {
  int nums1[] = {1};
  int nums2[] = {};

  merge(nums1, LENGTH(nums1), 1, nums2, LENGTH(nums2), 0);

  CU_ASSERT_TRUE(EQUAL(nums1, ((int[]){1})));
}

void test_merge_case3(void) {
  int nums1[] = {0};
  int nums2[] = {1};

  merge(nums1, LENGTH(nums1), 0, nums2, LENGTH(nums2), 1);

  CU_ASSERT_TRUE(EQUAL(nums1, ((int[]){1})));
}

void test_merge_case4(void) {
  int nums1[] = {4, 5, 6, 0, 0, 0};
  int nums2[] = {1, 2, 3};

  merge(nums1, LENGTH(nums1), 3, nums2, LENGTH(nums2), 3);

  CU_ASSERT_TRUE(EQUAL(nums1, ((int[]){1, 2, 3, 4, 5, 6})));
}
void test_merge_case5(void) {
  int nums1[] = {4, 0, 0, 0, 0, 0};
  int nums2[] = {1, 2, 3, 5, 6};

  merge(nums1, LENGTH(nums1), 1, nums2, LENGTH(nums2), 5);

  CU_ASSERT_TRUE(EQUAL(nums1, ((int[]){1, 2, 3, 4, 5, 6})));
}

int main(void) {
  CU_pSuite suite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  suite = CU_add_suite("MergeSortedArray", 0, 0);
  if (suite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite, "MergeSortedArray.case#1", test_merge_case1)) ||
      (NULL == CU_add_test(suite, "MergeSortedArray.case#2", test_merge_case2)) ||
      (NULL == CU_add_test(suite, "MergeSortedArray.case#3", test_merge_case3)) ||
      (NULL == CU_add_test(suite, "MergeSortedArray.case#4", test_merge_case4)) ||
      (NULL == CU_add_test(suite, "MergeSortedArray.case#5", test_merge_case5))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
