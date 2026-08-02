  class Solution { 
public: 
  int orangesRotting(vector<vector<int>>& grid) { 
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        // Queue stores pairs in the format: {{row, col}, time}
        queue<pair<pair<int,int>,int>> q; 
        
        // Initialize the visited matrix with the same dimensions as grid
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        
        int freshCnt = 0; // Track initial fresh oranges
        
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){ 
                if(grid[i][j] == 2){ 
                    q.push({{i, j}, 0}); // Fixed syntax: outer braces for pair
                    vis[i][j] = 2; 
                } else { 
                    vis[i][j] = 0; 
                }
                if(grid[i][j] == 1) {
                    freshCnt++; // Count fresh oranges
                }
            } 
        } 
        
        int tm = 0; 
        int cnt = 0; // Track how many fresh oranges get rotten
        
        // Correct array syntax
        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, 1, 0, -1}; 
        
        while(!q.empty()){ 
            int r = q.front().first.first; 
            int c = q.front().first.second; 
            int t = q.front().second; 
            tm = max(tm, t); 
            q.pop(); 
            
            for(int i = 0; i < 4; i++){ 
                int nrow = r + drow[i]; 
                int ncol = c + dcol[i]; // Fixed variable: changed ncol[i] to dcol[i]
                
                // Fixed boundary check (ncol < m) and variable names (nrow/ncol instead of row/col)
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){ 
                    q.push({{nrow, ncol}, t + 1}); // Push next time step (t + 1) instead of tm + 1
                    vis[nrow][ncol] = 2; 
                    cnt++; // Increment rotten count
                } 
            } 
        } 
        
        // If the number of fresh oranges infected doesn't match initial fresh count, return -1
        if(cnt != freshCnt) return -1;
        
        return tm; 
    } 
};