#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the size of the matrix (number of rows).
        int m = matrix[0].size(); // Get the size of a row (number of columns).

        // Step 1: Transpose the matrix by swapping rows and columns.
        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1; // Initialize low and high pointers for row swapping.
            while (low < high) {
                // Swap the elements at (low, i) and (high, i).
                swap(matrix[low][i], matrix[high][i]);
                low++; // Move the low pointer downwards.
                high--; // Move the high pointer upwards.
            }
        }

        // Step 2: Reverse each row to achieve the 90-degree clockwise rotation.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                // Swap the elements at (i, j) and (j, i).
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // The matrix is now rotated 90 degrees clockwise.
    }
};

int main() {
    int n, m; // Dimensions of the matrix
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    solution.rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
