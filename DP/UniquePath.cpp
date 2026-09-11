

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 1. Base Case: If start or end is blocked, no paths are possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        // 2. Initialize a 1D DP array for the row with 0s
        // Use 'long long' to prevent overflow during additions
        vector<long long> dp(n, 0);
        dp[0] = 1; // 1 way to start at the top-left cell

        // 3. Iterate through every cell grid row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If the current cell is an obstacle, it blocks all paths
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } 
                else {
                    // If we are not in the first column, add paths coming from the left
                    if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        // The final element holds the total paths to the bottom-right corner
        return dp[n - 1];
    }
};
