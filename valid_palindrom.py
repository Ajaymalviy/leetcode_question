class Solution:
    s="ajaJ"
    def isPalindrome(self, s: str) -> bool:
        # Initialize an empty string to store alphanumeric characters
        s1 = ""

        # Iterate through each character in the input string 's'
        for i in s:
            # Check if the character is alphanumeric
            if i.isalnum():
                # If it is, append it to the 's1' string
                s1 += i

        # Convert 's1' to lowercase for case-insensitive comparison
        k = s1.lower()

        # Check if the reversed 'k' is equal to 'k' itself
        if k[::-1] == k:
            # If it is, return True (string is a palindrome)
            return True
        else:
            # If it's not, return False (string is not a palindrome)
            return False
