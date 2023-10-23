class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // #If the current interval's ending point is less than the starting point of newInterval, add the current interval to the result array as is because there's no overlap.
  
        // If the current interval's starting point is greater than the ending point of newInterval, it means all remaining intervals will also not overlap with newInterval. In this case, add newInterval to the result array and then add the remaining intervals from intervals to the result array as is.

        
        // Add all intervals before the newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        
// If there is an overlap between the current interval and newInterval, update newInterval to merge these two intervals by taking the minimum starting point and maximum ending point of the two intervals.
        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        // Add all intervals after the newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};

