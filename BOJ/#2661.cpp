#include <iostream>

using namespace std;

int n;
string answer;

void permutation(char cur, int cnt){
    if (n+1 == cnt){
        cout << answer;
        exit(0);
    }
    answer += cur;

    // 검증
    for(int i = 1; i <= cnt/2; i++){
        string a = answer.substr(cnt - i, i);
        string b = answer.substr(cnt - 2*i, i);

        if (a == b){
            answer.erase(cnt-1);
            return;
        }
    }

    for(int i = 1; i <= 3; i++)
        permutation('0' + i, cnt+1);
    answer.erase(cnt-1);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= 3; i++){
        permutation('0'+i, 1);
    }
    return 0;
}