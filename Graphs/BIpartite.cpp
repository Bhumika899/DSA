class Solution {
private:
    bool check(int start, int V, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                // If adjacent node is not colored, give it the opposite color
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } 
                // If adjacent node has the same color, it's not bipartite
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // Use vector instead of variable-length array for safety and passing by reference
        vector<int> color(V, -1); 

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // Pass graph directly as the adjacency list, along with the color vector
                if (check(i, V, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};