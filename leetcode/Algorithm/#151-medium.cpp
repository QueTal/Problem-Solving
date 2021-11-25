/**
 * 151. Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        stack<char> st;
        for (auto c : s){
            if (c == ' '){
                string temp = "";
                if (st.empty()) continue;
                while(!st.empty()){
                    auto t = st.top(); st.pop();
                    temp = t + temp;     
                }
                ret = ret == "" ? temp: temp + " " + ret;
            }
            else st.push(c);
        }
        
        if (st.empty()) return ret;
        string temp = "";
        while(!st.empty()){
            auto t = st.top(); st.pop();
            temp = t + temp;     
        }
        ret = ret == "" ? temp : temp + " " + ret;
        return ret;
    }
};