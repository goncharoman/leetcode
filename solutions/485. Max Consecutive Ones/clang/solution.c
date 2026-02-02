#include "solution.h"

int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int count = 0, curr = 0;
  for (int i = 0; i < numsSize; i++) {
    curr = curr * nums[i] + nums[i];
    if (curr > count) {
      count = curr;
    }
  }
  return count;
}
