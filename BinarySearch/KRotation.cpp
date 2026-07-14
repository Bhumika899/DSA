class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int l=0;
        int  h=n-1;
        int ans=INT_MAX;
       int  index=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[l]<=arr[h]){
                if(arr[l]<ans){
                    index=l;
                    ans=arr[l];
                }
                break;
            }
            if(arr[l]<=arr[mid]){
                if(arr[l]<ans){
                    ans=arr[l];
                    index=l;
                    
                }
                l=mid+1;
            }else{
               
                if(arr[mid]<ans){
                    ans=arr[mid];
                    index=mid;
                }
                 h=mid-1;
            }
        }
        return index;
    }
};