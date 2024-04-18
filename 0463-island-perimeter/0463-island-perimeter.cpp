#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4; // Start with 4 sides for each land cell

                    // Check left neighbor
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2; // Subtract 2 if left neighbor is land
                    }
                    // Check top neighbor
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2; // Subtract 2 if top neighbor is land
                    }
                }
            }
        }

        return perimeter;
    }
};
