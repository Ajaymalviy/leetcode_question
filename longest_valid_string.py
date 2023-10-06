class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left, right = 0, 0
        max_length = 0

        # Left to right pass
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1

            if left == right:
                # If left and right parentheses counts match, we have a valid substring.
                # Update max_length with twice the count of matching parentheses.
                max_length = max(max_length, 2 * right)
            elif right > left:
                # If right parentheses count exceeds left parentheses count, reset counts.
                left = right = 0

        left = right = 0

        # Right to left pass
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1

            if left == right:
                # If left and right parentheses counts match, we have a valid substring.
                # Update max_length with twice the count of matching parentheses.
                max_length = max(max_length, 2 * left)
            elif left > right:
                # If left parentheses count exceeds right parentheses count, reset counts.
                left = right = 0

        return max_length

# Example usage:
solution = Solution()
input_str = "(()())"
result = solution.longestValidParentheses(input_str)
print("Longest valid parentheses substring length:", result)
