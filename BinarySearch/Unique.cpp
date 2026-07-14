class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int n = arr.size();
    
    // Hash map to store the count of each element
    unordered_map<int, int> cnt;
for (int i = 0; i < n; i++) {
        cnt[arr[i]]++;
    }
     for (auto p : cnt) {
        if (p.second == 1) {
            return p.first;
        }
    }
    return -1;
    }
};