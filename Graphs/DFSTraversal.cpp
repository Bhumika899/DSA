class Solution {
private:
    void DFSGraph(int node, vector<vector<int>>& adj,
                  vector<int>& vis, vector<int>& ls) {

        // Mark current node as visited
        vis[node] = 1;

        // Store current node in DFS traversal
        ls.push_back(node);

        // Visit all adjacent nodes
        for (auto it : adj[node]) {

            if (!vis[it]) {
                DFSGraph(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {

        int n = adj.size();

        // Visited array
        vector<int> vis(n, 0);

        // Stores DFS traversal
        vector<int> ls;

        // Start DFS from node 0
        DFSGraph(0, adj, vis, ls);

        return ls;
    }
};