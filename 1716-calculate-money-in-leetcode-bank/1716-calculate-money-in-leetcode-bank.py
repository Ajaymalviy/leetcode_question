class Solution:
    def totalMoney(self, n: int) -> int:
        total_money = 0
        start_money = 1

        for day in range(n):
            total_money += start_money + day % 7
            if day % 7 == 6:  # If it's a Sunday, update the starting money for the next Monday
                start_money += 1

        return total_money

# Example usage:
solution = Solution()
n = 10  # You can replace this with any value of n
result = solution.totalMoney(n)
print(result)
