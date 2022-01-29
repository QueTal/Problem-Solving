#include <iostream>
#include <stack>

using namespace std;

int main(void){
    stack<char> st;
    string input, answer;
    cin >> input;

    for (int i = 0; i < input.size(); i++){
        char s = input[i];
        if (isalnum(s)) answer += s;
        else {
            if (s == '(') st.push(s);
            else if (s == ')'){
                while (!st.empty() and st.top() != '('){
                    answer += st.top(); st.pop();
                }
                st.pop();
            }
            else if (s == '*' or s == '/'){
                while (!st.empty() and (st.top() == '*' or st.top() == '/')){
                    answer += st.top(); st.pop();
                }
                st.push(s);
            }
            else if (s == '+' or s == '-'){
                while (!st.empty() and st.top() != '('){
                    answer += st.top(); st.pop();
                }
                st.push(s);
            }
        }
    }
    while (!st.empty()){
        answer += st.top();
        st.pop();
    }
    cout << answer;
    return 0;
}
