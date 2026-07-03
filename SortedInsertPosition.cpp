class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=n;
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]>=k){
               ans=mid;
               h=mid-1;
               
            }else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};