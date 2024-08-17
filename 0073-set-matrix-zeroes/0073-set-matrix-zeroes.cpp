#include <vector>
#include <unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::unordered_set<int> zeroRows;
        std::unordered_set<int> zeroCols;

        // Identify the rows and columns to be zeroed

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Set the corresponding rows to zero
        for (int row : zeroRows) {
            for (int j = 0; j < n; ++j) {
                matrix[row][j] = 0;
            }
        }

        // Set the corresponding columns to zero
        for (int col : zeroCols) {
            for (int i = 0; i < m; ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};
