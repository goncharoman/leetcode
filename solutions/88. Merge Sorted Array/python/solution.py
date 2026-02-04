def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    if n == 0:
        return
    array = nums1
    midx, nidx = m - 1, n - 1
    for i in range(len(array) - 1, -1, -1):
        if midx == -1 or nums2[nidx] > nums1[midx]:
            array[i] = nums2[nidx]
            nidx -= 1
        else:
            array[i] = nums1[midx]
            midx -= 1

        if nidx == -1:
            return
