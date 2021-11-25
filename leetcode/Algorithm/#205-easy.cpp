/*
 * 205. Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings/
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m;
        string ss = "", tt = "";
        char target = 'a';
        
        for (auto c : s){
            if (m.count(c)) ss += m[c];
            else ss += target, m[c] = target++;
        }
        m.clear(); target = 'a';
        for (auto c : t){
            if (m.count(c)) tt += m[c];
            else tt += target, m[c] = target++;
        }
        return ss == tt;
    }
};