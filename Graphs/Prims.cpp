class Solution { 
public: 
    int spanningTree(int V, vector<vector<int>>& edges) { 
        // 1. Build the adjacency list from the given edges
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // 2. Initialize Prim's Algorithm
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        vector<int> vis(V, 0); 
        
        // Push starting node {weight, node}
        pq.push({0, 0}); 
        int sum = 0; 
        
        while(!pq.empty()){ 
            auto it = pq.top(); 
            pq.pop(); 
            
            int node = it.second; 
            int wt = it.first; 
            
            if(vis[node] == 1) continue; 
            vis[node] = 1; 
            sum += wt; 
            
            for(auto& iter : adj[node]){ 
                int adjNode = iter.first; 
                int edW = iter.second; 
                
                if(!vis[adjNode]){ 
                    pq.push({edW, adjNode}); 
                } 
            } 
        } 
        return sum; 
    } 
};
