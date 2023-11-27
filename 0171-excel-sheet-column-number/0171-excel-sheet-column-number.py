class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        for char in columnTitle:
            # Convert character to its corresponding numerical value
            value = ord(char) - ord('A') + 1
            # Accumulate the result by multiplying the existing result by 26 and adding the current value
            result = result * 26 + value
        return result
