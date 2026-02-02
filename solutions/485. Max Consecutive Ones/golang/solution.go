package solution

func findMaxConsecutiveOnes(nums []int) int {
	count, curr := 0, 0
	for _, num := range nums {
		curr = curr*num + num
		if curr > count {
			count = curr
		}
	}
	return count
}
