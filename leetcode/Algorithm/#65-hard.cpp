/*
 * https://leetcode.com/problems/valid-number/
 * 65. Valid Number
 */

class Solution {
public:
    bool isNumber(string s) {
        bool signFlag = false, digitFlag = false, dotFlag = false, expFlag = false;
        
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '+' or s[i] == '-'){
                if(signFlag or digitFlag or dotFlag) return false;
                signFlag = true;
            }
            else if(isdigit(s[i])){
                digitFlag = true;
            }
            else if(s[i] == '.'){
                if(dotFlag or expFlag) return false;
                dotFlag = true;
            }
            else if(s[i] == 'e' or s[i] == 'E'){
                if(expFlag or !digitFlag) return false;
                else {
                    expFlag = true; signFlag = false; digitFlag = false; dotFlag = false;
                }
            }
            else return false;
        }
        
        return digitFlag;
    }
};