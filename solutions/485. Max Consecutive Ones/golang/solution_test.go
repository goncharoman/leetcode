package solution

import (
	"fmt"
	"testing"
)

func TestFindMaxConsecutiveOnes(t *testing.T) {
	testCases := []struct {
		input  []int
		output int
	}{
		{[]int{1, 1, 0, 1, 1, 1}, 3},
		{[]int{1, 0, 1, 1, 0, 1}, 2},
	}

	for n, tc := range testCases {
		testname := fmt.Sprintf("case#%d", n)
		t.Run(testname, func(t *testing.T) {
			ans := findMaxConsecutiveOnes(tc.input)
			if ans != tc.output {
				t.Errorf("got %d, want %d", ans, tc.output)
			}
		})
	}
}

func BenchmarkFindMaxConsecutiveOnes(b *testing.B) {
	nums := []int{1, 1, 0, 1, 1, 1}
	for b.Loop() {
		findMaxConsecutiveOnes(nums)
	}
}
