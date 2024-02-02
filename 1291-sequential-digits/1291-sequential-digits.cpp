#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        
        // Generate all possible sequential digits from 1 to 9
        std::vector<int> sequentialDigits;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                sequentialDigits.push_back(num);
            }
        }
        
        // Filter the sequential digits within the range [low, high]
        for (int num : sequentialDigits) {
            if (num >= low && num <= high) {
                result.push_back(num);
            }
        }
        
        std::sort(result.begin(), result.end());
        return result;
    }
};
