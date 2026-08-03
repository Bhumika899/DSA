#include <vector>
using namespace std;

class Solution {
private:
    // Fixed parameter type from vector<int> vis[] to int vis[]
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode, node, vis, adj) == true) 
                    return true;
            }
            // If the neighbor is visited and is not the parent, a cycle exists
            else if(adjNode != parent) {
                return true; 
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        
        for(int i = 0; i < V; i++) {
            // FIXED: Changed vis[V] to vis[i]
            if(!vis[i]) { 
                if(dfs(i, -1, vis, adj) == true) 
                    return true;
            }
        }
        return false;
    }
}; // FIXED: Added missing semicolon
