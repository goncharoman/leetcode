package solution

import (
	"fmt"
	"reflect"
	"testing"
)

func TestMergeSortedArray(t *testing.T) {
	testCases := []struct {
		nums1 []int
		m     int
		nums2 []int
		n     int
		want  []int
	}{
		{[]int{1, 2, 3, 0, 0, 0}, 3, []int{2, 5, 6}, 3, []int{1, 2, 2, 3, 5, 6}},
		{[]int{1}, 1, []int{}, 0, []int{1}},
		{[]int{0}, 0, []int{1}, 1, []int{1}},
		{[]int{4, 5, 6, 0, 0, 0}, 3, []int{1, 2, 3}, 3, []int{1, 2, 3, 4, 5, 6}},
		{[]int{4, 0, 0, 0, 0, 0}, 1, []int{1, 2, 3, 5, 6}, 5, []int{1, 2, 3, 4, 5, 6}},
	}

	for n, tc := range testCases {
		testname := fmt.Sprintf("case#%d", n)
		t.Run(testname, func(t *testing.T) {
			merge(tc.nums1, tc.m, tc.nums2, tc.n)
			if !reflect.DeepEqual(tc.nums1, tc.want) {
				t.Errorf("got %d, want %d", tc.nums1, tc.want)
			}
		})
	}
}

func BenchmarkTestMergeSortedArrays(b *testing.B) {
	nums1, nums2 := []int{1, 2, 3, 0, 0, 0}, []int{2, 5, 6}
	m, n := 3, 3

	for b.Loop() {
		merge(nums1, m, nums2, n)
	}
}
