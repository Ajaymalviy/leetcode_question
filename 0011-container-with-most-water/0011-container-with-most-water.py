from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            # Calculate the width of the container
            width = right - left

            # Choose the minimum height between the two lines
            h = min(height[left], height[right])

            # Calculate the area and update max_area if needed
            area = width * h
            max_area = max(max_area, area)

            # Move the pointers towards each other
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area

# Example usage:
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
solution = Solution()
result = solution.maxArea(height)
print(result)
     
        