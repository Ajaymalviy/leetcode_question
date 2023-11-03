class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int current = 1;  // Initialize a variable to keep track of the current number to consider from the stream.
        
        for (int num : target) {
            while (current < num) {
                // Push the current number to the stack and record the "Push" operation.
                operations.push_back("Push");
                // Since the current number comes from the stream, increment it.
                current++;
                // We need to pop immediately after pushing, as the target number hasn't been reached yet.
                operations.push_back("Pop");
            }
            
            // If the current number is equal to the target number, no need to push it to the stack.
            // Instead, just record the "Push" operation.
            if (current == num) {
                operations.push_back("Push");
            }
            
            // Move to the next number in the stream.
            current++;
        }
        
        return operations;
    }
};
