class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int lar=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>lar){
                lar=arr[i];
                
            }
             
        }
      return lar;
    }
};
