class Solution {
private:
    void dfs(
        int row,
        int col,
        vector<vector<int>>& vis,
        vector<vector<char>>& grid,
        vector<pair<int, int>>& vec,
        int row0,
        int col0
    ) {
        // Mark current land cell as visited
        vis[row][col] = 1;

        // Store coordinates relative to the starting cell
        vec.push_back({row - row0, col - col0});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check valid, unvisited land cell
            if (
                nrow >= 0 &&
                nrow < n &&
                ncol >= 0 &&
                ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 'L'
            ) {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(
            n,
            vector<int>(m, 0)
        );

        // Stores unique island shapes
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start DFS from every unvisited land cell
                if (!vis[i][j] && grid[i][j] == 'L') {

                    vector<pair<int, int>> vec;

                    dfs(i, j, vis, grid, vec, i, j);

                    // Insert the island's shape
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};