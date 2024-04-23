#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0}; // Only one node, return it as the root label
        }
        
        // Step 1: Create an adjacency list
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        
        // Step 2: Enqueue all leaf nodes
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }
        
        // Step 3: Perform BFS
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (--degrees[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        // Step 4: Gather the remaining nodes in the queue (root labels of MHTs)
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};
