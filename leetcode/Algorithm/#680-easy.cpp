/**
 * 680. Valid Palindrome II
 * https://leetcode.com/problems/valid-palindrome-ii/
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        
        while (i < j){
            if (s[i] != s[j]) return checkParlindrome(s,i,j-1) or checkParlindrome(s,i+1,j);
            i++; j--;
        }
        return true;
    }
    
    bool checkParlindrome(string s, int i, int j){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};