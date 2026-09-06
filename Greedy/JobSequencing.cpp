#include <vector>
#include <algorithm>

class Solution {
    struct Job {
        int start;
        int end;
        int profit;
    };

public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        int n = startTime.size();
        std::vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // 1. Sort jobs by finish time
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end < b.end;
        });

        // 2. dp[i] stores the max profit using a subset of the first i jobs
        std::vector<int> dp(n + 1, 0);
        std::vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = jobs[i].end;
        }

        for (int i = 1; i <= n; ++i) {
            // Option 1: Skip the current job
            int excludeProfit = dp[i - 1];

            // Option 2: Include the current job
            // Find the last job that finishes on or before jobs[i-1].start
            int targetStart = jobs[i - 1].start;
            auto it = std::upper_bound(endTimes.begin(), endTimes.end(), targetStart);
            int prevCompatibleIndex = std::distance(endTimes.begin(), it); // 1-based index in dp

            int includeProfit = jobs[i - 1].profit + dp[prevCompatibleIndex];

            // Take the optimal choice
            dp[i] = std::max(excludeProfit, includeProfit);
        }

        return dp[n];
    }
};