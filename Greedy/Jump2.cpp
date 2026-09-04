class Solution {
public:
    int jump(vector<int>& nums) {
        // If there's only 1 element, we are already at the end
        if (nums.size() <= 1) return 0; 
        
        int jumps = 0;
        int l = 0;
        int r = 0;
        
        // Loop until the right bound reaches or exceeds the last index
        while (r < nums.size() - 1) {
            int farthest = 0;
            
            // Note: The loop condition must include 'r' (ind <= r)
            for (int ind = l; ind <= r; ind++) {
                farthest = max(farthest, ind + nums[ind]);
            }
            
            l = r + 1;
            r = farthest;
            jumps = jumps + 1;
        }
        
        return jumps;
    }
};
