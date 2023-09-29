class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        # Merge the two sorted lists while maintaining sorting order
        merged = []
        i = j = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        
        # Append remaining elements from nums1 and nums2
        merged.extend(nums1[i:])
        merged.extend(nums2[j:])
        
        length = len(merged)
        
        # Check if the total length is even or odd
        if length % 2 == 0:
            # If even, return the average of the two middle elements
            return (merged[length // 2 - 1] + merged[length // 2]) / 2
        else:
            # If odd, return the middle element
            return merged[length // 2]

# Prompt the user for input
nums1 = list(map(int, input("Enter the first sorted list (comma-separated): ").split(",")))
nums2 = list(map(int, input("Enter the second sorted list (comma-separated): ").split(",")))

solution = Solution()
median = solution.findMedianSortedArrays(nums1, nums2)
print("Median:", median)
