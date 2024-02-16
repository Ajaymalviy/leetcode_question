from typing import List
from collections import Counter

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        # Step 1: Count frequency of each integer
        counter = Counter(arr)
        
        # Step 2: Sort based on frequencies
        sorted_counts = sorted(counter.values())
        
        # Step 3: Remove the least frequent integers until k elements are removed
        unique_count = len(sorted_counts)
        for count in sorted_counts:
            if k >= count:
                k -= count
                unique_count -= 1
            else:
                break
        
        # Step 4: Return the count of unique integers remaining after removal
        return unique_count
