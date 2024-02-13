class Solution:
    def isPalindrome(self, word: str) -> bool:
        return word == word[::-1]

    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalindrome(word):
                return word
        return ""
