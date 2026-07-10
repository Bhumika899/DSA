class Solution {
public:
    int lowerBound(const vector<int>& arr, int n, int k) {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= k) {
                ans = mid;
                high = mid - 1; // Look for smaller index on the left
            } else {
                low = mid + 1; // Look on the right
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size(); // Number of columns
        
        int cnt_max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            // Find the first index of 1 using lowerBound
            int first_one_index = lowerBound(arr[i], m, 1);
            
            // Calculate total ones in this row
            int cnt_ones = m - first_one_index;
            
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};