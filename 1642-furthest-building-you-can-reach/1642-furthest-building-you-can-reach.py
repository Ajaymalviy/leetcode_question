from typing import List
import heapq

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        height_diffs = []
        for i in range(len(heights) - 1):
            diff = heights[i + 1] - heights[i]
            if diff > 0:
                heapq.heappush(height_diffs, diff)
                if len(height_diffs) > ladders:
                    bricks -= heapq.heappop(height_diffs)
                if bricks < 0:
                    return i
        return len(heights) - 1
