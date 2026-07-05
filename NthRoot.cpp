class Solution {
public:
    long long power(long long base, int exp) {
        long long ans = 1;

        while (exp--) {
            ans *= base;
        }

        return ans;
    }

    int nthRoot(int n, int m) {

        if (m == 0)
            return 0;

        int low = 1;
        int high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long val = power(mid, n);

            if (val == m)
                return mid;

            else if (val < m)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};