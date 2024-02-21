class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        # Count the number of shifts needed to make left and right equal
        shift = 0
        while left < right:
            left >>= 1
            right >>= 1
            shift += 1

        # Left shift left by the number of shifts to get the common bits
        return left << shift