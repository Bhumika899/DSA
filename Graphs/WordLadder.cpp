class Solution { 
public: 
    int wordLadder(vector<string> &words, string &s, string &e) { 
        // Use the parameter 'e' as the target word directly
        queue<pair<string, int>> q; 
        q.push({s, 1}); 
        
        // Fix: Change unordered_set type from int to string
        unordered_set<string> st(words.begin(), words.end()); 
        st.erase(s); 
        
        while(!q.empty()){ 
            string word = q.front().first; 
            int steps = q.front().second; 
            q.pop(); 
            
            // Fix: Compare with the end word parameter 'e'
            if(word == e) return steps; 
            
            for(int i = 0; i < word.size(); i++){ 
                char original = word[i]; 
                for(char ch = 'a'; ch <= 'z'; ch++){ 
                    word[i] = ch; 
                    if(st.find(word) != st.end()){ 
                        st.erase(word); 
                        q.push({word, steps + 1}); 
                    } 
                } 
                word[i] = original; 
            } 
        } 
        return 0; 
    } 
};