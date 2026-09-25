class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0;
        int cookie = 0;
        
        while (child < g.size() && cookie < s.size()) {
            // If the cookie satisfies the child's greed
            if (s[cookie] >= g[child]) {
                child++; // Move to the next child
            }
            cookie++; // Always move to the next cookie
        }
        
        return child; // Total number of satisfied children
    }
};
