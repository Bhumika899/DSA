class Solution {
  public:
    bool isPossible(int maxTime,  vector<int>& arr, int k) {
    int painters = 1;    
    int currSum = 0;     

    for (int length : arr) {
        
        // if a board is longer than maxTime,
        // it's impossible to assign
        if (length > maxTime)
            return false;

        // if assigning this board exceeds maxTime, 
        // give it to a new painter
        if (currSum + length > maxTime) {
            painters++;        
            currSum = length;  
        } 
        
        // otherwise, continue adding to the current 
        // painter's workload
        else {
            currSum += length;
        }
    }

    // return true if total painters used is
    // within the allowed k
    return painters <= k;
}

int minTime(vector<int>& arr, int k) {
    
    // lower limit is the largest board 
    // (can't split boards)
    int low = *max_element(arr.begin(), arr.end());

    // upper limit is the sum of all board lengths 
    // (one painter does all)
    int high = accumulate(arr.begin(), arr.end(), 0);

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        // if this time allows us to paint
        // with k painters or fewer
        if (isPossible(mid, arr, k)) {
            result = mid;     
            high = mid - 1;   
        } 
        
        // if not possible, we need to allow 
        // more time
        else {
            low = mid + 1;
        }
    }

    return result;
}
};