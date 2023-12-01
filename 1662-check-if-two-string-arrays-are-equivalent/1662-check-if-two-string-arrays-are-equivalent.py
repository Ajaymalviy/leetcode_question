class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        # Concatenate elements of both arrays into strings
        str1 = ''.join(word1)
        str2 = ''.join(word2)
        
        # Compare the two strings
        return str1 == str2

# Example usage:
word1 = ["ab", "c"]
word2 = ["a", "bc"]

sol = Solution()
result = sol.arrayStringsAreEqual(word1, word2)
print(result)
