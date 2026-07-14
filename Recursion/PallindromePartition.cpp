#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(0, s, path, res);
        return res;
    }

    void fun(int index, const string& s, vector<string>& path, vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) { 
            if (isPali(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                fun(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPali(const string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

int main() {
    Solution solver;
    string input = "aab";
    
    cout << "Input string: " << input << endl;
    cout << "All palindrome partitions:" << endl;
    
    vector<vector<string>> result = solver.partition(input);
    
    // Print the results
    for (const auto& partition : result) {
        cout << "[ ";
        for (const auto& str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
