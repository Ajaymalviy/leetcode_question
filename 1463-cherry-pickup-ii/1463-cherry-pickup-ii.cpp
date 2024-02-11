#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return dfs(grid, memo, 0, 0, cols - 1);
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int row, int col1, int col2) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Check if we have reached the bottom row
        if (row == rows - 1) {
            return (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        }
        
        // Check if the result for the current state is already calculated
        if (memo[row][col1][col2] != -1) {
            return memo[row][col1][col2];
        }
        
        int cherries = 0;
        
        // Explore all possible movements for both robots
        for (int newCol1 = max(0, col1 - 1); newCol1 <= min(cols - 1, col1 + 1); ++newCol1) {
            for (int newCol2 = max(0, col2 - 1); newCol2 <= min(cols - 1, col2 + 1); ++newCol2) {
                cherries = max(cherries, dfs(grid, memo, row + 1, newCol1, newCol2));
            }
        }
        
        // Add current cell's cherries if both robots are not on the same cell
        if (col1 != col2) {
            cherries += grid[row][col1] + grid[row][col2];
        } else {
            cherries += grid[row][col1];
        }
        
        // Update memoization table
        memo[row][col1][col2] = cherries;
        
        return cherries;
    }
};
