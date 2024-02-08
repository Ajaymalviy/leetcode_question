#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the least number of perfect squares needed to sum to each number from 0 to n
        std::vector<int> dp(n + 1, INT_MAX);
        
        // Base case: 0 requires 0 perfect squares to sum up to
        dp[0] = 0;
        
        // Iterate from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Iterate over all possible perfect squares that are less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update the dp[i] if taking the current perfect square (j*j)
                // reduces the number of perfect squares needed to sum up to i
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        // The least number of perfect squares needed to sum up to n is stored in dp[n]
        return dp[n];
    }
};
