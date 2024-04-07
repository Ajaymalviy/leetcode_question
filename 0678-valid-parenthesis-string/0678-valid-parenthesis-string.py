class Solution:
    def checkValidString(self, s: str) -> bool:
        # Track the minimum and maximum possible count of open parentheses
        min_open = 0
        max_open = 0
        
        # Iterate through the string
        for char in s:
            if char == '(':
                min_open += 1
                max_open += 1
            elif char == ')':
                min_open = max(0, min_open - 1)  # Treat '*' as empty string if needed
                max_open -= 1
                if max_open < 0:  # More ')' than '(' or '*'
                    return False
            else:  # char == '*'
                min_open = max(0, min_open - 1)  # Treat '*' as empty string
                max_open += 1
        
        # All remaining '*' can be treated as empty string
        return min_open == 0
