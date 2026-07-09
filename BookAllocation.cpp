class Solution {
public:
    // Changed pages to long long to match the binary search variable type safely
    int countStu(vector<int>& arr, long long pages) {
        int students = 1; 
        long long pagesStudent = 0; 
        for(int i = 0; i < arr.size(); i++) {
            if(pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i]; 
            } else {
                students += 1; 
                pagesStudent = arr[i]; 
            }
        } 
        return students; 
    } 

    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if(k > n) return -1; 
        
        // Upgraded search space bounds to long long to prevent 32-bit integer overflow
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL); // 0LL ensures 64-bit accumulation
        long long ans = -1; 

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            int students = countStu(arr, mid);
            
            if(students <= k) { 
                ans = mid;
                high = mid - 1;
            } else { 
                low = mid + 1; 
            }
        } 
        return ans; 
    }
};