/**
 * 890. Find and Replace Pattern
 * https://leetcode.com/problems/find-and-replace-pattern/
 */

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {       
        vector<string> v;
        for (string word : words) {
            if (checkPatternMatch(word, pattern)) v.push_back(word);
        }
        return v;
    }
    
    bool checkPatternMatch(string word, string pattern){
        unordered_map<char, char> m;
        
        for (int i = 0; i < word.size(); i++){
            if (m.end() == m.find(word[i])) {
                m[word[i]] = pattern[i];
            }
            else if (m[word[i]] != pattern[i]) return false;
        }
    
        vector<bool> seen(26, false);
        for (auto iter = m.begin(); iter != m.end(); iter++){
            if (seen[iter->second - 'a']) return false;
            seen[iter->second - 'a'] = true;
        }
        return true;
    }
};