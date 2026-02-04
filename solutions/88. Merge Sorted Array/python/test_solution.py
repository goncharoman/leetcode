import unittest

from solution import merge


class MergeTestCase(unittest.TestCase):
    def testMergeSortedArrays(self):
        testcases = [
            (([1, 2, 3, 0, 0, 0], 3), ([2, 5, 6], 3), [1, 2, 2, 3, 5, 6]),
            (([1], 1), ([], 0), [1]),
            (([0], 0), ([1], 1), [1]),
            (([4, 5, 6, 0, 0, 0], 3), ([1, 2, 3], 3), [1, 2, 3, 4, 5, 6]),
            (([4, 0, 0, 0, 0, 0], 1), ([1, 2, 3, 5, 6], 5), [1, 2, 3, 4, 5, 6]),
        ]

        for (nums1, m), (nums2, n), expected in testcases:
            with self.subTest(nums1=nums1, m=m, nums2=nums2, n=n):
                self.assertEqual(merge(nums1, m, nums2, n), None)
                self.assertEqual(nums1, expected)
