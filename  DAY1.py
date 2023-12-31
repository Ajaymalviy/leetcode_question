def two_sum(nums, target):
    # Create a dictionary to store the complement of each number and index
    dict = {}
    
    for i, num in enumerate(nums):
        complement = target - num
        
        # Check if the complement exists in the dictionary
        if complement in dict:
            return [dict[complement], i]
        
        # Add the current number and its index to the dictionary
        dict[num] = i
    
    # if no solution is found, return empty list
    return []


nums = [2, 7, 11, 15]
target = 9
result = two_sum(nums, target)
print(result)                                                # Output: [0, 1]