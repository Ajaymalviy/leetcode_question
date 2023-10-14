// Default 4x4 matrix for explanation
vector<vector<int>> matrix = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
    { 13, 14, 15, 16 }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;  // Create a vector to store the spiral order result.

        // Check if the input matrix is empty or has an empty first row, and return an empty result if true.
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int rows = matrix.size();    // Get the number of rows in the matrix.
        int cols = matrix[0].size(); // Get the number of columns in the matrix.
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1; // Define the boundaries of the current spiral.

        // Continue while there are unprocessed elements within the defined boundaries.
        while (left <= right && top <= bottom) {
            // Traverse from left to right within the top boundary.
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down.

            // Traverse from top to bottom within the right boundary.
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary to the left.

            // If there are unprocessed rows, traverse from right to left within the bottom boundary.
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up.
            }

            // If there are unprocessed columns, traverse from bottom to top within the left boundary.
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary to the right.
            }
        }

        return result; // Return the result vector containing the elements in spiral order.
    }
};
