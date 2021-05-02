#include <iostream>

using namespace std;

int countDiff(string a, string b){
    int cnt = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main(void){
    string a, b;
    int alen, blen, answer = 100000;

    cin >> a >> b;
    alen = a.size(); blen = b.size();

    for(int i = 0; i < blen-alen+1; i++){
        int temp = countDiff(a, b.substr(i, alen));
        if(answer > temp) answer = temp;
    }

    cout << answer;
    return 0;
}