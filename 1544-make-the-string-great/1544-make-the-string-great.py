class Solution:
    def makeGood(self, s: str) -> str:
        stack = []  # Use a stack to keep track of characters
        for char in s:
            # Check if the stack is not empty and the current character, when converted to lowercase,
            # is equal to the top element of the stack when converted to lowercase and the characters are different
            if stack and char.lower() == stack[-1].lower() and char != stack[-1]:
                stack.pop()  # Remove the top element from the stack
            else:
                stack.append(char)  # Otherwise, add the character to the stack
        return ''.join(stack)  # Join the characters in the stack to form the resulting string

