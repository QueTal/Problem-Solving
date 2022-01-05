#include <iostream>

using namespace std;

int N;
int dp[1001][10];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 10; j++){
            for (int k = j; k < 10; k++){
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= 10007;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) sum += dp[N][i];

    cout << sum % 10007;

    return 0;
}