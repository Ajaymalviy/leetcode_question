class Solution:
    def countVowelPermutation(self, n: int) -> int:
        MOD = 10**9 + 7

        # Initialize a 2D array to store the counts.
        # dp[i][j] represents the number of valid strings of length i ending with vowel j.
        dp = [[0] * 5 for _ in range(n)]

        # Initialize the counts for strings of length 1 (base case).
        for j in range(5):
            dp[0][j] = 1

        # Define the transition rules.
        transitions = {
            0: [1],          # 'a' can only be followed by 'e'
            1: [0, 2],       # 'e' can be followed by 'a' or 'i'
            2: [0, 1, 3, 4], # 'i' can't be followed by another 'i'
            3: [2, 4],       # 'o' can be followed by 'i' or 'u'
            4: [0]           # 'u' can only be followed by 'a'
        }

        for i in range(1, n):
            for j in range(5):
                for k in transitions[j]:
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD

        # Sum up the counts for all the vowels for a string of length n.
        total_count = sum(dp[n - 1]) % MOD

        return total_count

# Example usage:
solution = Solution()
n = 5
result = solution.countVowelPermutation(n)
print(result)



