class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
          int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==x) return true;
            else if(matrix[row][col]<x) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    
};