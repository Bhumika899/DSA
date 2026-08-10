class Solution {
private:
    void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    // Changed back to 2 parameters to match the driver code exactly
    vector<int> shortestPath(int V, vector<vector<int>>& edges) { 
        int M = edges.size(); // Dynamically get the number of edges
        
        // 1. Create the adjacency list using V
        vector<pair<int,int>> adj[V];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt}); 
        }

        // 2. Perform Topological Sort
        int vis[V] = {0};
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // 3. Relax distances in topological order
        vector<int> dist(V, 1e9); 
        dist[0] = 0;

        while(!st.empty()) { 
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) { 
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // 4. Convert unreachable nodes to -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};