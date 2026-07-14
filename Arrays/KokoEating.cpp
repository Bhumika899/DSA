class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int x : piles)
            maxi = max(maxi, x);
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;

        for (int x : piles) {
            totalH += (1LL * x + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findMax(piles);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (calculateTotalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};