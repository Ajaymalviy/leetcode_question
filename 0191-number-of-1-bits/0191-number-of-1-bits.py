class Solution:
    def hammingWeight(self, n: int) -> int:
        # Initialize a variable to count the number of '1' bits
        count = 0
        
        # Iterate through each bit using a for loop
        for i in range(32):  # Assuming 32-bit integers
            # Check if the current bit is set (equal to 1)
            if (n >> i) & 1:
                count += 1
        
        return count
