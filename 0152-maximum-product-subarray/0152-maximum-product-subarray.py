class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        #if nums list is empty then directly return zero  
        # at first we intialize all three variable with zero th index of nums list
        max_product = nums[0]
        min_product = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):  # move in list from 1 index to end of its size
            # Swap max_product and min_product if the current number is negative
            if nums[i] < 0:
                max_product, min_product = min_product, max_product

            # Update max and min products ending at the current element
            max_product = max(nums[i], max_product * nums[i])
            min_product = min(nums[i], min_product * nums[i])

            # Update the overall maximum product
            result = max(result, max_product)

        return result

# Example usage:
solution = Solution()
nums = [2, 3, -2, 4]
max_product = solution.maxProduct(nums)
print(max_product)  # Output: 6 (the subarray [2, 3] has the largest product)
