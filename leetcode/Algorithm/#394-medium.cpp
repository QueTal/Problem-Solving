/**
 * 394. Decode String
 * https://leetcode.com/problems/decode-string/
 */

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        string res = "";
        int num = 0;
        
        for(char c : s){
            if (isdigit(c)) num = num * 10 + c-'0';
            else if (isalpha(c)) res += c;
            else if (c == '['){
                nums.push(num);
                str.push(res);
                res = ""; 
                num = 0;
            }
            else if (c == ']'){
                string temp_res = res;
                int temp_num = nums.top(); nums.pop();
                for (int i = 0 ; i < temp_num - 1; i++) res += temp_res;
                res = str.top() + res;
                str.pop();
            }
        }
        return res;
    }
};