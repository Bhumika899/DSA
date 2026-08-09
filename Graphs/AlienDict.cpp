class Solution {
public:
    string findOrder(vector<string> &words) {
        int N = words.size();
        
        // 1. Dynamically calculate K (the number of unique characters present)
        set<int> uniqueChars;
        for (const string &word : words) {
            for (char ch : word) {
                uniqueChars.insert(ch - 'a');
            }
        }
        int K = uniqueChars.size();

        // Map the unique characters to continuous index bounds [0, K-1]
        // This resolves the issue where characters like 'd', 'b', 'c' don't span continuously from 'a'
        vector<int> charMap(26, -1);
        vector<char> revMap(K);
        int index = 0;
        for (int chIdx : uniqueChars) {
            charMap[chIdx] = index;
            revMap[index] = (char)(chIdx + 'a');
            index++;
        }

        // Graph representations bounded by actual unique character count K
        vector<vector<int>> graph(K);
        vector<int> inDegree(K, 0);

        // 2. Build the graph by comparing adjacent words
        for (int i = 0; i + 1 < N; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            
            // Edge Case: If a longer word appears before its own prefix, it's invalid
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return ""; 
            }

            int len = min(w1.length(), w2.length());
            int j = 0;
            while (j < len && w1[j] == w2[j]) {
                ++j;
            }

            if (j < len) {
                int u = charMap[w1[j] - 'a'];
                int v = charMap[w2[j] - 'a'];
                
                graph[u].push_back(v);
                inDegree[v]++;
            }
        }

        // 3. Kahn's Algorithm for Topological Sort
        queue<int> q;
        for (int i = 0; i < K; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        string result = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += revMap[u]; // Map sorted integer index back to its unique alien character

            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle Detection Check
        if (result.length() < K) {
            return "";
        }

        return result;
    }
};