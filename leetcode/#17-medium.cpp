/* 
 * 17. Letter Combinations of a Phone Number 
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        char arr[10][4] = {{'-', '-', '-', '-'}, 
                           {'-', '-', '-', '-'}, {'a', 'b', 'c', '-'}, {'d', 'e', 'f', '-'},
                           {'g', 'h', 'i', '-'}, {'j', 'k', 'l', '-'}, {'m', 'n', 'o', '-'},
                           {'p', 'q', 'r', 's'}, {'t', 'u', 'v', '-'}, {'w', 'x', 'y', 'z'}};
        int digit[5], i = 0;
        vector<string> v;
        
        if(digits == "") return {};
        while(digits.size() != 0){
            digit[i++] = stoi(digits.substr(0, 1));
            digits = digits.substr(1);
        }
        
        
        make_comb(digit, arr, i, 0, "", v);
        return v;
    }
    void make_comb(int digit[5], char arr[][4], int len, int idx, string s, vector<string>& v){
        if(len == idx){
            v.push_back(s);
            return;
        }      
        
        for(int i = 0; i < 4; i++){
            if(arr[digit[idx]][i] != '-') make_comb(digit, arr, len, idx+1, s+arr[digit[idx]][i], v);
        }
    }
};