/*
 * 1047. Remove All Adjacent Duplicates In String
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string answer = "";
        
        for(char x: s){
            if (st.empty() or st.top() != x) st.push(x);
            else st.pop();
        }
        
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};