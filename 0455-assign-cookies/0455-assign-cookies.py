from typing import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # Sort the lists in ascending order
        g.sort()
        s.sort()

        # Initialize pointers for both lists
        i, j = 0, 0
        content_children = 0

        # Iterate through both lists
        while i < len(g) and j < len(s):
            # If the current cookie size is sufficient for the child's greed
            if s[j] >= g[i]:
                # Assign the cookie to the child and move to the next child and cookie
                content_children += 1
                i += 1
            j += 1

        return content_children
