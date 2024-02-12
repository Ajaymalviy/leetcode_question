class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCandidate = nums[0];
        int count = 1;

        // Find majority candidate
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == majorityCandidate) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    majorityCandidate = nums[i];
                    count = 1;
                }
            }
        }

        // Verify if the majority candidate is indeed the majority element
        count = 0;
        for (int num : nums) {
            if (num == majorityCandidate) {
                ++count;
            }
        }

        if (count > nums.size() / 2) {
            return majorityCandidate;
        } else {
            // If majority element doesn't exist (not specified in problem statement)
            // you may return any valid default value here
            return -1;
        }
    }
};
