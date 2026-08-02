class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newcolor, int delRow[], int delCol[], int inicolor) {
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            // Fixed: Check 'image[nrow][ncol]' instead of 'image[row][col]'
            // Fixed: Check 'ans[nrow][ncol]' instead of 'ans[row][col]'
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor) {
                // Fixed: Added missing 'inicolor' argument to the recursive call
                dfs(nrow, ncol, ans, image, newcolor, delRow, delCol, inicolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Fixed: Passed 'color' instead of the undefined variable 'newcolor'
        dfs(sr, sc, ans, image, color, delRow, delCol, inicolor);
        return ans;
    }
};
