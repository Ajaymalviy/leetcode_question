class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = ""
        
        while columnNumber > 0:
            # Subtract 1 to map 1-26 to 0-25 for A-Z
            columnNumber -= 1
            # Get the remainder when divided by 26 to determine the letter
            remainder = columnNumber % 26
            # Convert the remainder to ASCII and append to the result
            result = chr(ord('A') + remainder) + result
            # Update columnNumber to be the result of integer division by 26
            columnNumber //= 26
        
        return result
