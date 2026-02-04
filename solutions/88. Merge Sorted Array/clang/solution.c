#include "solution.h"

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  if (n == 0) {
    return;
  }
  int midx = m - 1;
  int nidx = n - 1;
  for (int i = m + n - 1; i >= 0; i--) {
    if (midx == -1 || nums2[nidx] > nums1[midx]) {
      nums1[i] = nums2[nidx];
      nidx--;
    } else {
      nums1[i] = nums1[midx];
      midx--;
    }

    if (nidx == -1) {
      return;
    }
  }
}
