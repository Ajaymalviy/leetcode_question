class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(n, 1); // Number of nodes in the subtree rooted at each node
        vector<int> sum(n, 0);   // Sum of distances from each node to all other nodes
        
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    dfs1(neighbor, node);
                    count[node] += count[neighbor];
                    sum[node] += sum[neighbor] + count[neighbor];
                }
            }
        };
        
        dfs1(0, -1); // Start DFS from the root node
        
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    // Update sum of distances for the current node based on its parent's information
                    sum[neighbor] = sum[node] - count[neighbor] + n - count[neighbor];
                    dfs2(neighbor, node);
                }
            }
        };
        
        dfs2(0, -1); // Start DFS from the root node
        
        return sum;
    }
};
