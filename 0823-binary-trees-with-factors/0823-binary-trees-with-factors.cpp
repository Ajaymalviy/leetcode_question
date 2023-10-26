class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1000000007;

        // Step 1: Sort the input array in ascending order
        sort(arr.begin(), arr.end());
        
        int n = arr.size();

        // Step 2: Initialize a map to store the number of binary trees for each element
        unordered_map<int, long long> dp;

        // Step 3: Iterate through the elements in the array
        for (int i = 0; i < n; i++) {
            // Step 4: Initialize the count of binary trees for the current element to 1
            dp[arr[i]] = 1;
            
            // Step 5: Iterate through the elements before the current element
            for (int j = 0; j < i; j++) {
                // Step 6: Check if the current element is divisible by the previous element
                if (arr[i] % arr[j] == 0) {
                    // Step 7: Calculate the complement, which is the result of the division
                    int complement = arr[i] / arr[j];

                    // Step 8: Check if the complement exists in the dp map
                    if (dp.count(complement)) {
                        // Step 9: Update the count of binary trees for the current element
                        // by adding the product of counts for the previous element and its complement
                        dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[complement]) % MOD) % MOD;
                    }
                }
            }
        }
        
        // Step 10: Calculate the total number of binary trees by summing up all counts in the dp map
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + dp[arr[i]]) % MOD;
        }
        
        // Step 11: Return the total number of binary trees modulo 10^9 + 7
        return static_cast<int>(total);
    }
};
