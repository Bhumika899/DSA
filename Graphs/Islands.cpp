class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& grid, int n, int m) {

        // Boundary, visited, and water check
        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || grid[i][j] != 'L') {
            return;
        }

        // Mark current land cell as visited
        vis[i][j] = true;

        // Visit all 8 directions

        dfs(i - 1, j, vis, grid, n, m);     // Up
        dfs(i + 1, j, vis, grid, n, m);     // Down
        dfs(i, j - 1, vis, grid, n, m);     // Left
        dfs(i, j + 1, vis, grid, n, m);     // Right

        dfs(i - 1, j - 1, vis, grid, n, m); // Top-left
        dfs(i - 1, j + 1, vis, grid, n, m); // Top-right
        dfs(i + 1, j - 1, vis, grid, n, m); // Bottom-left
        dfs(i + 1, j + 1, vis, grid, n, m); // Bottom-right
    }

    int countIslands(vector<vector<char>>& grid) {

        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        vector<vector<bool>> vis(
            n,
            vector<bool>(m, false)
        );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found an unvisited land cell
                if (grid[i][j] == 'L' && !vis[i][j]) {

                    // Visit the complete island
                    dfs(i, j, vis, grid, n, m);

                    // Count one complete island
                    islands++;
                }
            }
        }

        return islands;
    }
};