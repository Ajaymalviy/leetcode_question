from typing import List

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        threshold = n // 4  # 25% of the array length

        for i in range(n):
            if i + threshold < n and arr[i] == arr[i + threshold]:
                return arr[i]

# Example usage:
arr = [1, 2, 2, 6, 6, 6, 6, 7, 10]
solution = Solution()
result = solution.findSpecialInteger(arr)
print(result)
