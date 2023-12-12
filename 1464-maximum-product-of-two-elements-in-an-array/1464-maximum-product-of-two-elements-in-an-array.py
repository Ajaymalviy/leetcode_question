class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1 = max2 = float('-inf')  # Initialize max1 and max2 to negative infinity

        # Iterate through the array
        for num in nums:
            if num > max1:
                max2 = max1
                max1 = num
            elif num > max2:
                max2 = num

        # Calculate the maximum product
        return (max1 - 1) * (max2 - 1)
