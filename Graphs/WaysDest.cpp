class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Using long long for weights to prevent overflow
        vector<pair<int, long long>> adj[n];
        for(auto& it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Min-heap: stores {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        

        vector<long long> dist(n, 1e18); // Use a large value for long long
        vector<int> ways(n, 0);
        
        dist[0] = 0; 
        ways[0] = 1;
        pq.push({0, 0});
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            long long d = pq.top().first; 
            int node = pq.top().second;
            pq.pop();
            
            // Optimization: Skip processing if we found a better path already
            if (d > dist[node]) continue;
            
            for(auto& it : adj[node]){
                int adjNode = it.first;
                long long edW = it.second;
                
                // Found a shorter path to adjNode
                if(d + edW < dist[adjNode]){
                    dist[adjNode] = d + edW;
                    pq.push({dist[adjNode], adjNode}); 
                    ways[adjNode] = ways[node];
                } 
                // Found another path of the same shortest length
                else if(d + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; 
                }
            }
        }
        return ways[n - 1];
    }
};