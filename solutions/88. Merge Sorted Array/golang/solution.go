package solution

func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		return
	}
	midx, nidx := m-1, n-1
	for k := m + n - 1; k >= 0; k-- {
		if midx == -1 || nums2[nidx] > nums1[midx] {
			nums1[k] = nums2[nidx]
			nidx--
		} else {
			nums1[k] = nums1[midx]
			midx--
		}

		if nidx == -1 {
			return
		}
	}
}
