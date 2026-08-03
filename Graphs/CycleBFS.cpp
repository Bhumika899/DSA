class Solution {
private:
    // Helper function using BFS to detect a cycle in a component
    bool detect(int src, const vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q; // {node, parent}
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                } 
                // If an adjacent node is visited and is not the parent, a cycle exists
                else if (parent != adjNode) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // 1. Build the adjacency list from the given edges list
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. Track visited nodes across multiple disconnected components
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};