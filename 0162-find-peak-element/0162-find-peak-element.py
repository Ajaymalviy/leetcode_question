from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            # Compare the middle element with its neighbors
            if nums[mid] > nums[mid + 1]:
                # If mid is greater than its right neighbor, move left
                right = mid
            else:
                # If mid is not greater than its right neighbor, move right
                left = mid + 1

        # At the end of the loop, left and right will be equal, and that index will be a peak
        return left
