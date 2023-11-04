class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = 0;
        int rightMax = 0;

        // Find the maximum position of ants moving to the left.
        for (int position : left) {
            leftMax = max(leftMax, position);
        }

        // Find the maximum position of ants moving to the right.
        for (int position : right) {
            rightMax = max(rightMax, n - position);
        }

        // Return the maximum between the two maxima to determine the last ant(s) falling out.
        return max(leftMax, rightMax);
    }
};
