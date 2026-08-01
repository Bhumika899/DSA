class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            // If there is a connection and the neighbor hasn't been visited yet
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            // If the city is not visited, it belongs to a new province
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited); // Mark all connected cities as visited
            }
        }
        
        return provinces;
    }
};
