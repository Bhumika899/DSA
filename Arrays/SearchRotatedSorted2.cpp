class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code here
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<=h){
             int mid = l + (h - l) / 2; 
             if(arr[mid]==key){
                 return true;
             }
              if(arr[l]==arr[mid]&& arr[mid]==arr[h]){
                  l++;
                  h--;
                  continue;
              }
              //left half is sorted
              if (arr[l] <= arr[mid]) {
              if(arr[l]<=key && key<arr[mid]){
                  h=mid-1;
              }else{
                  l=mid+1;
              }
              }
              //right is sorted
            else{
                if(arr[mid]<key && key<=arr[h]){
                      l = mid + 1;
           } else{
                h= mid - 1;
                }
            }
              
        }
        return false;
    }
};