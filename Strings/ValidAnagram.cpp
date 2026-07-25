class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
    if (s.length() != t.length()) return false;
    
    // for lowercase a-z
    vector<int> freq(26, 0);  
    
    // Count frequency of each character in s1
    for(char ch : s) 
        freq[ch - 'a']++;
    
    // Subtract frequency using characters from s2
    for(char ch : t) 
        freq[ch - 'a']--;
    
    // If any count is not zero, not an anagram
    for(int count : freq) {
        if (count != 0)
            return false;
    }
    
    return true;

 
    }
};