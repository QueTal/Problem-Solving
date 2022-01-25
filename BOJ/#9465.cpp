#include <iostream>

using namespace std;

int dp[2][100001], arr[2][100001];
int T, N;

int solve(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[0][i];
    for (int i = 0; i < N; i++) cin >> arr[1][i];

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = arr[0][1] + dp[1][0];
    dp[1][1] = arr[1][1] + dp[0][0];
    for (int i = 2; i < N; i++){
        dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }
    return max(dp[0][N-1], dp[1][N-1]);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while (T--){
        cout << solve() << "\n";
    }
}