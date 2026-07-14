class Solution { 
public: 
    int FirstOccur(vector<int> &arr, int k) { 
        int n = arr.size(); 
        int l = 0; 
        int h = n - 1; 
        int first = -1; 
        while(l <= h){ 
            int mid = l + (h - l) / 2; // Prevents potential integer overflow
            if(arr[mid] == k){ 
                first = mid; 
                h = mid - 1; 
            } 
            else if(arr[mid] < k) l = mid + 1; 
            else h = mid - 1; 
        } 
        return first; 
    } 

    int LastOccur(vector<int> &arr, int k) { 
        int n = arr.size(); 
        int last = -1; 
        int l = 0; 
        int h = n - 1; 
        while(l <= h){ 
            int mid = l + (h - l) / 2; 
            if(arr[mid] == k){ 
                last = mid; 
                l = mid + 1; 
            } else if(arr[mid] < k) l = mid + 1; 
            else h = mid - 1; 
        } 
        return last; 
    } 

    vector<int> find(vector<int>& arr, int x) { 
        int first = FirstOccur(arr, x); 
        if(first == -1) return {-1, -1}; 
        
        int last = LastOccur(arr, x); 
        return {first, last}; 
    } 