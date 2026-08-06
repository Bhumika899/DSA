class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state) {
        state[node] = 1;   // Visiting

        for (int nei : adj[node]) {
            if (state[nei] == 1)
                return true;

            if (state[nei] == 0) {
                if (dfs(nei, adj, state))
                    return true;
            }
        }

        state[node] = 2;   // Visited
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges) {

        // Build adjacency list
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> state(V, 0);

        for (int i = 0; i < V; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state))
                    return true;
            }
        }

        return false;
    }
};