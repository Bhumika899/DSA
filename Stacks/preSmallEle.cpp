class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        vector<int>ans(arr.size(),0);
        stack<int>s;
        for(int i=0;i<arr.size();i++){
            while(s.size()>0 && s.top()>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }else{
                ans[i]=s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
};