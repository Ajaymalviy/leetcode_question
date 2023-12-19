
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        if not img or not img[0]:
            return []

        rows, cols = len(img), len(img[0])
        result = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                result[i][j] = self.calculate_average(img, i, j)

        return result

    def calculate_average(self, img, i, j):
        rows, cols = len(img), len(img[0])
        total_sum, count = 0, 0

        for ni in range(max(0, i - 1), min(i + 2, rows)):
            for nj in range(max(0, j - 1), min(j + 2, cols)):
                total_sum += img[ni][nj]
                count += 1

        return total_sum // count
