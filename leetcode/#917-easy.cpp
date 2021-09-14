/**
 * 917. Reverse Only Letters
 * https://leetcode.com/problems/reverse-only-letters/
 */ 

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int lo = 0, hi = s.size()-1;
        
        while (lo < hi){
            if (!isalpha(s[lo])) { lo++; continue; }
            if (!isalpha(s[hi])) { hi--; continue; }
            
            swap(s[lo], s[hi]);
            lo++; hi--;
        }
        return s;
    }
};