class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // Use vector instead of 'list'
        deque<int> dq;      // Use deque instead of 'list[],dq'
        
        for (int i = 0; i < nums.size(); i++) { // Loop must go until nums.size() - 1
            // 1. Remove indices that are out of the current window bounds
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 2. Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index to the back of the deque
            dq.push_back(i);
            
            // 4. If the window has reached size k, the front is the max element
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
