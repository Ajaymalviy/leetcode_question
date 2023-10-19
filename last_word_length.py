class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Remove leading and trailing whitespace from the input string 's'
        stripped = s.strip()
        
        # Split the stripped string into a list of words using space (' ') as the delimiter
        strList = stripped.split(" ")
        
        # Extract the last word from the list (if any words exist)
        lastWord = strList[-1]
        
        # Calculate and return the length of the last word
        return len(lastWord)

# Define the input string 's' outside the class
s = "there is a man"

# Create an instance/obj of the Solution class
solution = Solution()

# Call the lengthOfLastWord method on the instance
result = solution.lengthOfLastWord(s)

# Print the result
print(result)