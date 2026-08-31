
class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;

        // Traverse from right to left for NSE
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
};
