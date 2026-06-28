#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void recur(int index, vector<int>& nums, vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for (int i = index; i < nums.size(); i++) {

            if (st.find(nums[i]) != st.end())
                continue;

            st.insert(nums[i]);

            swap(nums[index], nums[i]);

            recur(index + 1, nums, ans);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = obj.permuteUnique(nums);

    cout << "Unique Permutations are:\n";

    for (auto &perm : ans) {
        for (int x : perm)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}