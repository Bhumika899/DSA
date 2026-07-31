class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        queue<int> q;
        
        // Start BFS from node 0
        vis[0] = 1;
        q.push(0);
        
        vector<int> bfs_result;
        
        while (!q.empty()) {
            
            int node = q.front();
            q.pop();
            
            // Store the current node
            bfs_result.push_back(node);
            
            // Visit all adjacent nodes
            for (int it : adj[node]) {
                
                if (vis[it] == 0) {
                    
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs_result;
    }
};