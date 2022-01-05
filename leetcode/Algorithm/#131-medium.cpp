/**
 * 131. Palindrome Partitioning
 * https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> cur;
        
        dfs(answer, cur, s);
        return answer;
    }
    
    void dfs(vector<vector<string>>& answer, vector<string>& cur, string s){
        if (s == "") answer.push_back(cur);
        
        for (int i = 1; i <= s.length(); i++){
            string sb = s.substr(0, i);
            if (isPalindrome(sb)) {
                cur.push_back(sb);
                dfs(answer, cur, s.substr(i));
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        int lo = 0, hi = s.length()-1;
        while (lo < hi){
            if (s[lo] != s[hi]) return false;
            lo++; hi--;
        }
        return true;
    }
};