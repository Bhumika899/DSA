class Solution {
  public:
  int findDays(vector<int>&arr,int cap){
      int days=1,load=0;
      for(int i=0;i<arr.size();i++){
          if(arr[i]+load>cap){
              days=days+1;
              load=arr[i];
              
          }else{
             load+=arr[i];
          }
      }
      return days;
  }
    int leastWeightCapacity(vector<int>& arr, int D) {
        // code here
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
         int ans = high;
        while(low<=high){
            int mid = low + (high - low) / 2;
            int numberOfDays=findDays(arr,mid);
            if(numberOfDays<=D){
                ans=mid;
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return low;
        
    }
};