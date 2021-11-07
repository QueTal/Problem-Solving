/**
 * 43. Multiply Strings
 * https://leetcode.com/problems/multiply-strings/
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size() + num2.size();
        string answer(n, '0');
        
        for (int i = 0; i < num2.size(); i++){
            int digit2 = num2[i] - '0';
            
            for (int j = 0; j < num1.size(); j++){
                int digit1 = num1[j] - '0';
                
                int start = i+j;
                int carry = answer[start] - '0';
                int multiply = digit1 * digit2 + carry;
                
                answer[start] = (multiply % 10) + '0';
                
                answer[start+1] += (multiply/10);
            }
        }
        if (answer.back() == '0') answer.pop_back();
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};