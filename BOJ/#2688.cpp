#include <iostream>

using namespace std;

int N;
long long dp[65][10];

long long count(){
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 1; i <= N; i++) dp[i][0] = 1;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j < 10; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    long long res = 0;
    for (int i = 0; i < 10; i++) res += dp[N][i];
    return res;
}

int main(void){
    int T;
    cin >> T;

    while (T--){
        cin >> N;
        cout << count() << endl;
    }
    return 0;
}