class Solution {
public:
    // 1. Signature fixed to match the Driver code's parameters
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // 2. Build the adjacency list internally using a vector of pairs: adj[node] -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Assuming an undirected graph based on standard practice problems
        }

        // 3. Min-heap priority queue storing {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 4. Distance array initialized to a large value (infinity)
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int current_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Optimization: Skip processing if a shorter path was already discovered
            if (current_dist > dist[node]) continue;
            
            // 5. Correctly iterate through neighbors and their edge weights
            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                // Relaxation step
                if (current_dist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = current_dist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};