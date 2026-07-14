class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;
        
        int low = 1, high = n;
        int ans = 1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2; // Prevents overflow
            long long square = mid * mid;
            
            if (square <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
