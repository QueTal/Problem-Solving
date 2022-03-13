/**
 * 20. Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/submissions/
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s){
            if(c == '(' or c == '[' or c == '{') st.push(c);
            else{
                if(st.empty()) return false;
                else {
                    if(c == ')' and st.top() != '(') return false;
                    if(c == ']' and st.top() != '[') return false;
                    if(c == '}' and st.top() != '{') return false;
                    st.pop();
                }
            }
        }
        return st.empty() ? true : false;
    }
};