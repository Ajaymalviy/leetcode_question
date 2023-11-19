class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        # Sort the array in descending order
        nums.sort(reverse=True)  

        # Initialize the count of operations and the next largest value
        operations = 0
        next_largest = nums[0]
        
        # Iterate through the array starting from the second element
        for i in range(1, len(nums)):
            # Compare the current element with the next largest element
            if nums[i] < next_largest:
                # If the current element is smaller, increment operations by its index
                operations += i
            
            # Update the next largest value for the next iteration
            next_largest = nums[i]

        # Return the total number of operations
        return operations
    

