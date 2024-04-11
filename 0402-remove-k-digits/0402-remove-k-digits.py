class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        removed = 0
        
        for digit in num:
            # Pop digits from the stack while they are larger than the current digit
            while stack and removed < k and stack[-1] > digit:
                stack.pop()
                removed += 1
            
            stack.append(digit)
        
        # Remove remaining digits from the end if k digits haven't been removed yet
        while removed < k:
            stack.pop()
            removed += 1
        
        # Remove leading zeros
        result = ''.join(stack).lstrip('0')
        
        # If the result is empty, return '0'
        return result if result else '0'

# Example usage:
# sol = Solution()
# num = "1432219"
# k = 3
# print(sol.removeKdigits(num, k))  # Output: "1219"
