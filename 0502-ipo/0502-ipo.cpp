#include <vector>
#include <queue>
#include <utility> // for pair
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Create pairs of (capital, profit) for easy sorting
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort projects based on their capital requirement
        sort(projects.begin(), projects.end());
        
        // Max heap to store profits of projects we can start
        priority_queue<int> pq;
        
        int currentCapital = w;
        int projectIndex = 0;
        
        // Process up to k projects
        for (int i = 0; i < k; ++i) {
            // Add all projects whose capital requirement is <= currentCapital into max heap
            while (projectIndex < n && projects[projectIndex].first <= currentCapital) {
                pq.push(projects[projectIndex].second);
                projectIndex++;
            }
            
            // If we have projects we can start, pick the one with max profit
            if (!pq.empty()) {
                currentCapital += pq.top();
                pq.pop();
            } else {
                break; // No more projects we can afford
            }
        }
        
        return currentCapital;
    }
};
