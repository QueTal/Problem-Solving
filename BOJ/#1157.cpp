#include <iostream>

using namespace std;

int main(void){
    string s, answer;
    bool check = false;
    int arr[26] = {0,};
    int cnt = 0;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
        if('A' <= s[i] and s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    
    for(int i = 0; i < s.size(); i++)
        arr[s[i] - 'a']++;
    
    for(int i = 0; i < 26; i++){
        if(arr[i] == 0) continue;
        if(arr[i] > cnt){
            cnt = arr[i];
            check = false;
            answer = i+'A';
        }
        else if(arr[i] == cnt) {
            check = true;
        }
    }
    if(check) cout << "?";
    else cout << answer;
    
    return 0;
}