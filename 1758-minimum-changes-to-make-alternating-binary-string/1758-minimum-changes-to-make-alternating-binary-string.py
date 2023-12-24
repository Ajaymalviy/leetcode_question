class Solution:
    def minOperations(self, s: str) -> int:
        # Count operations when the string starts with '0'
        count_starting_with_0 = 0
        for i in range(len(s)):
            if i % 2 == 0 and s[i] != '0':
                count_starting_with_0 += 1
            elif i % 2 == 1 and s[i] != '1':
                count_starting_with_0 += 1

        # Count operations when the string starts with '1'
        count_starting_with_1 = 0
        for i in range(len(s)):
            if i % 2 == 0 and s[i] != '1':
                count_starting_with_1 += 1
            elif i % 2 == 1 and s[i] != '0':
                count_starting_with_1 += 1

        # Return the minimum count
        return min(count_starting_with_0, count_starting_with_1)
