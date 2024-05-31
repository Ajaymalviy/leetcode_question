class Solution(object):
    def singleNumber(self, nums):
        # Step 1: XOR all numbers to get xor_result
        xor_result = 0
        for num in nums:
            xor_result ^= num

        # Step 2: Find a bit that is set in xor_result (rightmost set bit)
        diff_bit = xor_result & -xor_result

        # Step 3: Partition the numbers and XOR within each group to find the unique numbers
        num1, num2 = 0, 0
        for num in nums:
            if num & diff_bit:
                num1 ^= num  # XOR for the group with the set bit
            else:
                num2 ^= num  # XOR for the group without the set bit

        return [num1, num2]

# Example usage:
# solution = Solution()
# nums = [4, 1, 2, 1, 2, 5]
# print(solution.singleNumber(nums))  # Output: [4, 5] or [5, 4]

        