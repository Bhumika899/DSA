class Solution {
public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        int m = mat[0].size(); // Fixed: Ensure column size is pulled from row 0
        
        // Extract indices properly using vector notation
        int srcRow = src[0];
        int srcCol = src[1];
        int destRow = dest[0];
        int destCol = dest[1];
        
        // Rule 1: If source or destination cell is blocked (0), traversal is impossible
        if (mat[srcRow][srcCol] == 0 || mat[destRow][destCol] == 0) {
            return -1;
        }
        
        // Rule 2: If source matches destination and is valid, 0 steps are needed
        if (srcRow == destRow && srcCol == destCol) {
            return 0;
        }
        
        // Queue to store coordinates: {row, col}
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        // Initialize the source point
        dist[srcRow][srcCol] = 0;
        q.push({srcRow, srcCol});
        
        // Direction vectors for moving Up, Right, Down, Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int r = it.first;
            int c = it.second;
            
            // If we popped the destination cell, return its step count
            if (r == destRow && c == destCol) {
                return dist[r][c];
            }
            
            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                // Ensure boundary checks, valid walkable space (1), and a strictly shorter path
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && 
                    mat[newr][newc] == 1 && dist[r][c] + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = dist[r][c] + 1;
                    q.push({newr, newc});
                }
            }
        }
        return -1;
    }
};
