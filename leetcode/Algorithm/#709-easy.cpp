/*
 * 709. To Lower Case
 * https://leetcode.com/problems/to-lower-case/
 */ 

class Solution {
public:
    string toLowerCase(string s) {
        string temp = "";
        for(auto ss: s){
            if('A' <= ss and ss <= 'Z') temp += ss - 'A' + 'a';
            else temp += ss;
        }
        return temp;
    }
};