class Solution:
    def isPowerOfTwo(self, x: int) -> bool:
        if x <= 0:  # If x is 0 or less than zero, return False
            return False
        return (x & (x - 1)) == 0

# Get input from the user
try:
    user_input = int(input("Enter an integer: "))
    
    # Create an instance of the Solution class
    solution = Solution()

    # Check if the input is a power of two using the isPowerOfTwo method
    result = solution.isPowerOfTwo(user_input)

    if result:
        print(f"{user_input} is a power of two.")
    else:
        print(f"{user_input} is not a power of two.")
except ValueError:
    print("Invalid input. Please enter an integer.")
