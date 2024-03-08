class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
          # Step 1: Count the frequency of each element using Counter
        freq = Counter(nums)
        
        # Step 2: Find the maximum frequency among all elements
        max_freq = max(freq.values())
        
        # Step 3: Count how many elements have the maximum frequency
        max_freq_elements = sum(1 for f in freq.values() if f == max_freq)
        
        # Step 4: Calculate the total frequencies of elements with the maximum frequency
        total_freq = max_freq * max_freq_elements
        
        return total_freq
