#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> m;

int check(string s){
    m[s[0]]++;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1] and m.count(s[i])) return 0;
        else m[s[i]]++;
    }
    return 1;
}

int main(void){
    int n, count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        count += check(s);
        m.clear();
        // cout << s << endl;
    }
    cout << count << endl;
    return 0;
}