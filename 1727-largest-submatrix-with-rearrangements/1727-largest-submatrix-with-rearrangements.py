
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])

        #  Compute the height of each column
        for i in range(1, m):
            for j in range(n):
                if matrix[i][j] == 1:
                    matrix[i][j] += matrix[i - 1][j]

        # Calculate the maximum area of the rectangle for each row
        max_area = 0
        for i in range(m):
            # Sort the heights of columns for each row
            matrix[i].sort(reverse=True)

            # Calculate the maximum area using the sorted heights
            for j in range(n):
                max_area = max(max_area, matrix[i][j] * (j + 1))

        return max_area


