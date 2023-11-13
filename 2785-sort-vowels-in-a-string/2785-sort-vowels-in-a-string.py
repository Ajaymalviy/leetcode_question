class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        vowel_indices = [i for i, char in enumerate(s) if char in vowels]
        sorted_vowels = sorted([s[i] for i in vowel_indices])

        result = ''
        vowel_index = 0

        for i, char in enumerate(s):
            if char in vowels:
                result += sorted_vowels[vowel_index]
                vowel_index += 1
            else:
                result += char

        return result

# Example usage:
solution = Solution()
s = "leetcode"
result = solution.sortVowels(s)
print(result)
