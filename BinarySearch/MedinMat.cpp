class Solution {
public:
    // Helper function to find the first element strictly greater than x
    int upperBound(vector<int>& arr, int x, int m) {
        int low = 0;
        int high = m - 1;
        int ans = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Fixed: Changed 'k' to 'x'
            if (arr[mid] > x) { 
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Helper function to count elements <= x in the entire matrix
    int countSmall(vector<vector<int>>& mat, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // Fixed: Upper bound must be checked against the column size 'm'
            cnt += upperBound(mat[i], x, m); 
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        // Find the absolute minimum and maximum elements in the row-sorted matrix
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]); // Fixed: Used column size 'm-1' instead of 'n-1'
        }
        
        // Fixed: Median requires more than half of total elements to be <= to it
        int req = (n * m) / 2; 
        int ans = low;
        
        // Binary search on the value range [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (countSmall(mat, n, m, mid) <= req) {
                low = mid + 1;
            } else {
                ans = mid; // Potential median candidate
                high = mid - 1;
            }
        }
        return ans;
    }
};
