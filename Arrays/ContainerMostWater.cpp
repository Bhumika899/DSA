class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxArea=0;
        int l=0,r=n-1;
        while(l<r){
            int height=min(arr[l],arr[r]);
            int width=r-l;
            int area=height*width;
            maxArea=max(maxArea,area);
            if(arr[l]<=arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};