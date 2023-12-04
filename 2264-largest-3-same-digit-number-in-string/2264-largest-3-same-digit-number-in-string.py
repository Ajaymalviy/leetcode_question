class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        max_good_integer = ""

        # Iterate through all possible substrings of length 3
        for i in range(n - 2):
            current_substring = num[i:i + 3]

            # Check if the substring is a good integer
            if len(set(current_substring)) == 1:
                # Update the maximum good integer found so far
                max_good_integer = max(max_good_integer, current_substring)

        return max_good_integer

# Example usage:
solution = Solution()
result = solution.largestGoodInteger("1231234")
print(result)
  