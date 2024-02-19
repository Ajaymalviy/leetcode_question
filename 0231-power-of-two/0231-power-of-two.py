class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        #return false if this is negative or zero
        while n % 2 == 0:
            n //= 2
        return n == 1
    
