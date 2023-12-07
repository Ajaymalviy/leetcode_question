class Solution:
    def largestOddNumber(self, num: str) -> str:
        # Start from the rightmost digit
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 == 1:
                # If the rightmost digit is odd, return the substring
                return num[:i + 1]
        # If no odd integer is found, return an empty string
        return ""
