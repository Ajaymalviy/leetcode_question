class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int max_length = 0;
        int sum = 0;

        // Initialize the hashmap with a base case
        hashmap[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is 0, decrement the sum; otherwise, increment the sum
            sum += (nums[i] == 0) ? -1 : 1;

            // If the sum has been encountered before, update the maximum length
            if (hashmap.find(sum) != hashmap.end()) {
                max_length = max(max_length, i - hashmap[sum]);
            } else {
                // Otherwise, store the current sum along with its index
                hashmap[sum] = i;
            }
        }

        return max_length;
    }
};
