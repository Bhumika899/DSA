
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int counter = t.size();
        int begin = 0, end = 0;
        int d = INT_MAX, head = 0;

        while (end < s.size()) {
            if (freq[s[end++]]-- > 0) {
                counter--;
            }

            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - begin;
                }

                if (freq[s[begin++]]++ == 0) {
                    counter++;
                }
            }
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
