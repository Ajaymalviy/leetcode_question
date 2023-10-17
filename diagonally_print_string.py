from typing import List

class Solution:
    def printVertically(self, s: str = "Hello World") -> List[str]:
        # Split the input string into words
        words = s.split()
        
        # Find the maximum word length among the words
        max_length = max(len(word) for word in words)
        
        # Initialize an empty list to store vertically printed words
        vertical_words = []
        
        # Iterate through character positions (0 to max_length)
        for i in range(max_length):
            vertical_word = ""
            
            # Iterate through each word in the input
            for word in words:
                if i < len(word):
                    # Append the character to the vertical word
                    vertical_word += word[i]
                else:
                    # If the word is shorter, append a space
                    vertical_word += " "
            
            # Append the vertical word to the result list, removing trailing spaces
            vertical_words.append(vertical_word.rstrip())

        return vertical_words
