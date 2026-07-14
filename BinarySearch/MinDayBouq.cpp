class Solution {
public:

    bool possible(vector<int>& arr, int day, int m, int k) {

        int cnt = 0;
        int bouq = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] <= day) {
                cnt++;
            }
            else {
                bouq += cnt / k;
                cnt = 0;
            }
        }

        bouq += cnt / k;

        return bouq >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {

        long long val = 1LL * m * k;

        if (val > arr.size())
            return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int x : arr) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        int low = mini;
        int high = maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;