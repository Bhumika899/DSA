#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

private:
   
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<int>& mark) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
               
                dfs(it, node, vis, adj, tin, low, mark);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // 1. Convert the edge list into an adjacency list
        vector<int> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. Initialize tracking vectors using V instead of undefined 'n'
        vector<int> vis(V, 0);
        vector<int> mark(V, 0);
        int tin[V];
        int low[V];

        // Reset timer for multiple test cases
        timer = 1; 

        // 3. Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, mark);
            }
        }

        // 4. Collect the articulation points
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0) return {-1};
        return ans;
    }
};
