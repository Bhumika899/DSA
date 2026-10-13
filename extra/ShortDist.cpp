
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> indexes;
        vector<int> sol;

        // Step 1: Store all occurrences of c
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                indexes.push_back(i);
            }
        }

        // Step 2: Find minimum distance for each index
        for (int i = 0; i < s.length(); i++) {
            int min_dist = INT_MAX;

            for (int j : indexes) {
                min_dist = min(min_dist, abs(j - i));
            }

            sol.push_back(min_dist);
        }

        return sol;
    }
};
