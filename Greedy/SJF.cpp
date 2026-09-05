class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int t=0;
        int wt=0;
        int n=bt.size();
        for(int i=0;i<n;i++){
            wt+=t;
            t+=bt[i];
        }
        return (wt/n);
    }
};