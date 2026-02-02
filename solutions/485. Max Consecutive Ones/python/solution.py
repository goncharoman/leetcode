def findMaxConsecutiveOnes(nums: list[int]) -> int:
    count, curr = 0, 0
    for num in nums:
        curr = curr * num + num
        if curr > count:
            count = curr
    return count
