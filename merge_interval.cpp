#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;  // Using the namespace in the global scope

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1)
            return intervals;  // If there's only one interval, no need to merge

        // Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            // Check if the current interval overlaps with the previous one
            if (end >= intervals[i][0]) {
                // Merge by updating the end time
                end = max(end, intervals[i][1]);
            } else {
                // Add the merged interval to the result and start a new one
                mergedIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Add the last merged interval
        mergedIntervals.push_back({start, end});

        return mergedIntervals;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    for (const vector<int>& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
