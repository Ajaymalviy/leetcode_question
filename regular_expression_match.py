class Solution:

    def func(self, i, j):
        # Check if we have already calculated the result for this (i, j) pair
        if self.dp[i][j] != -1:
            return self.dp[i][j]

        # Base case: if both the string and pattern are exhausted, it's a match
        if i == len(self.s) and j == len(self.p):
            return True

        # Handle cases where the string is exhausted but pattern isn't
        if i >= len(self.s):
            # If there are characters followed by '*' in the pattern, skip them
            while j < len(self.p) - 1:
                if self.p[j + 1] == "*":
                    j += 2
                else:
                    return False
            # Check if the pattern is exhausted as well
            if j >= len(self.p):
                return True
            return False

        # Handle cases where the pattern is exhausted but the string isn't
        if j >= len(self.p):
            return False

        a = False
        b = False

        # Check if the current character and next character in the pattern
        # form a valid expression (e.g., a letter and '*')
        if j < len(self.p) - 1:
            if self.p[j + 1] == "*":
                if self.s[i] == self.p[j] or self.p[j] == ".":
                    a = self.func(i + 1, j)
                b = self.func(i, j + 2)
            elif self.p[j] == ".":
                a = self.func(i + 1, j + 1)
            else:
                if self.p[j] == self.s[i]:
                    a = self.func(i + 1, j + 1)
                else:
                    return False

        # Handle cases where there is no '*' in the pattern or the next character
        # is not '*'
        elif self.p[j] == ".":
            a = self.func(i + 1, j + 1)
        else:
            if self.p[j] == self.s[i]:
                a = self.func(i + 1, j + 1)
            else:
                return False

        # Save the result in the DP table and return the result
        self.dp[i][j] = a or b
        return a or b

    def isMatch(self, s: str, p: str) -> bool:
        self.s = s
        self.p = p
        self.dp = [[-1 for i in range(len(p) + 1)] for j in range(len(s) + 1)]
        return self.func(0, 0)
