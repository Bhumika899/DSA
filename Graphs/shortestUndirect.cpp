class Solution {
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Create adjacency list using V
        vector<int> adj[V];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // Remove this line if the graph is directed
        }
        
        // Initialize distance array with a large value
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        // BFS Queue
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        
        // Return destination distance, or -1 if unreachable
        return dist[dest] == 1e9 ? -1 : dist[dest];
    }
};
