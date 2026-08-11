class Solution {
public:

    // parent[word] = all words that can come
    // immediately before "word" in a shortest path
    unordered_map<string, vector<string>> parent;

    // Final answer
    vector<vector<string>> result;

    // Used while doing DFS/backtracking
    vector<string> path;


    // ------------------------------------------------
    // DFS: Build paths backwards from endWord to beginWord
    // ------------------------------------------------
    void dfs(string word, string beginWord) {

        // Add current word to path
        path.push_back(word);


        // We reached the starting word
        if (word == beginWord) {

            // Currently path is backwards
            // Example:
            // cog -> dog -> dot -> hot -> hit

            vector<string> temp = path;

            // Make it:
            // hit -> hot -> dot -> dog -> cog
            reverse(temp.begin(), temp.end());

            result.push_back(temp);

            path.pop_back();

            return;
        }


        // Try every possible parent
        for (string p : parent[word]) {

            dfs(p, beginWord);
        }


        // Backtracking
        path.pop_back();
    }


    // ------------------------------------------------
    // Main function
    // ------------------------------------------------
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        // Put all dictionary words into a set
        // so lookup becomes O(1) average
        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );


        // endWord MUST exist in wordList
        if (!dict.count(endWord)) {
            return {};
        }


        // BFS queue
        queue<string> q;

        q.push(beginWord);


        // dist[word] = shortest distance from beginWord
        unordered_map<string, int> dist;

        dist[beginWord] = 0;


        // ---------------------------------------------
        // BFS
        // ---------------------------------------------

        bool found = false;


        while (!q.empty() && !found) {

            // Process only the current BFS level
            int levelSize = q.size();


            for (int i = 0; i < levelSize; i++) {

                string current = q.front();
                q.pop();


                // Change every character
                for (int j = 0; j < current.size(); j++) {

                    string next = current;


                    // Try a -> z
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        next[j] = ch;


                        // If next isn't in dictionary,
                        // it isn't a valid word
                        if (!dict.count(next)) {
                            continue;
                        }


                        // -----------------------------------
                        // First time reaching "next"
                        // -----------------------------------

                        if (!dist.count(next)) {

                            // next is one level after current
                            dist[next] = dist[current] + 1;


                            // current is a parent of next
                            parent[next].push_back(current);


                            // Add next to BFS queue
                            q.push(next);
                        }


                        // -----------------------------------
                        // Another shortest way to reach next
                        // -----------------------------------

                        else if (
                            dist[next] ==
                            dist[current] + 1
                        ) {

                            parent[next].push_back(current);
                        }


                        // We found the end word
                        if (next == endWord) {
                            found = true;
                        }
                    }
                }
            }
        }


        // endWord was never reached
        if (!dist.count(endWord)) {
            return {};
        }


        // ---------------------------------------------
        // DFS to generate all shortest paths
        // ---------------------------------------------

        dfs(endWord, beginWord);


        return result;
    }
};