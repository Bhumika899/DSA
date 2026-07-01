class Solution {
    void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            
            // FIX 1: Changed nextj < n (was nextj <= n)
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) { 
        int n = maze.size();
        vector<string> ans;
        
        // Edge case: If start or end is blocked
        if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        // FIX 2: Corrected direction vectors to match "DLRU"
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0}; 
        
        // FIX 3 & 4: Corrected maze[0][0] check and passed 'maze' instead of 'm'
        if (maze[0][0] == 1) solve(0, 0, maze, n, ans, "", vis, di, dj);
        
        return ans;
    }
};
