class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";
        
        string st = ""; // Using string as a stack for easier reconstruction
        
        for (int i = 0; i < n; i++) {
            // Maintain a monotonic increasing sequence in the stack
            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        
        // If k is still greater than 0, remove digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < st.size() && st[start] == '0') {
            start++;
        }
        
        // Slice the string from the first non-zero character
        string res = st.substr(start);
        
        return res.empty() ? "0" : res;
    }
};
