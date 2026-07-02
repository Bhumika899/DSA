class Solution {
public:
    bool binarySearch(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        
        while (l <= h) {
            // Recalculate mid inside the loop to avoid an infinite loop
            int mid = l + (h - l) / 2; 
            
            if (arr[mid] == k) {
                return true; // Target found, return boolean true
            } else if (arr[mid] > k) {
                h = mid - 1; // Shrink search space to the left half
            } else {
                l = mid + 1; // Shrink search space to the right half
            }
        }
        
        return false; // Target not found, return boolean false
    }
};
