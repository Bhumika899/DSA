#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int t[301]; // Memoization array (adjust size based on constraint, e.g., max string length)

    bool solve(int idx, string &s) {
        int n = s.length();
        
        // Base Case: Successfully segmented the entire string
        if (idx >= n) {
            return true; 
        }

        // Return cached result if already calculated
        if (t[idx] != -1) {
            return t[idx];
        }

        // Try prefixes starting from length 1 up to the remaining length of the string
        for (int l = 1; idx + l <= n; l++) {
            string temp = s.substr(idx, l);
            
            // If prefix exists in dictionary, check the remaining substring recursively
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = true; // Cache and return true
            }
        }

        return t[idx] = false; // Cache and return false
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Clear set and memoization array for clean execution
        st.clear();
        memset(t, -1, sizeof(t)); 

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
