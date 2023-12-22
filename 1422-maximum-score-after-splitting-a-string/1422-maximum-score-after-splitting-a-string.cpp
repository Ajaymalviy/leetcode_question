#include <string>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int zerosOnLeft = 0;
        int onesOnRight = std::count(s.begin(), s.end(), '1'); // Count the total number of ones in the string
        int maxScore = 0;

        // Iterate through the string, excluding the last character
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                zerosOnLeft++;
            } else {
                onesOnRight--;
            }

            // Calculate the current score and update the maximum score
            int currentScore = zerosOnLeft + onesOnRight;
            maxScore = std::max(maxScore, currentScore);
        }

        return maxScore;
    }
};
