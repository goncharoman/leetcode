import unittest

from solution import findMaxConsecutiveOnes


class FindMaxConsecutiveOnesTestCase(unittest.TestCase):
    def test(self):
        testcases = (
            ([1, 1, 0, 1, 1, 1], 3),
            ([1, 0, 1, 1, 0, 1], 2),
        )

        for nums, expected in testcases:
            with self.subTest(nums=nums):
                self.assertEqual(findMaxConsecutiveOnes(nums=nums), expected)
