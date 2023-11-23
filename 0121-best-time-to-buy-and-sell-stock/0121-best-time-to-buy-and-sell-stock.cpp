#include <vector>
#include <limits> // for INT_MAX
#include <algorithm> // for max

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }

        int min_price = std::numeric_limits<int>::max(); // initialize to a very large value
        int max_profit = 0;

        for (int price : prices) {
            // Update the minimum price encountered so far
            min_price = std::min(min_price, price);

            // Update the maximum profit if selling at the current price yields a better profit
            max_profit = std::max(max_profit, price - min_price);
        }

        return max_profit;
    }
};
