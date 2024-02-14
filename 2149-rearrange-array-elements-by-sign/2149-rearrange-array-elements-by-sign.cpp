class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Count positive and negative numbers
        int posCount = 0, negCount = 0;
        for (int num : nums) {
            if (num > 0) {
                posCount++;
            } else {
                negCount++;
            }
        }

        // Ensure equal number of positive and negative numbers
        if (posCount != negCount) {
            return {}; // Handle invalid input: return empty vector
        }

        // Create alternating positive and negative vectors
        vector<int> pos, neg;
        for (int num : nums) {
            if (num > 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        // Merge alternating positive and negative elements
        vector<int> result(2 * posCount);
        int i = 0, j = 0;
        for (int k = 0; k < 2 * posCount; k++) {
            if (k % 2 == 0) {
                result[k] = pos[i++];
            } else {
                result[k] = neg[j++];
            }
        }

        return result;
    }
};
