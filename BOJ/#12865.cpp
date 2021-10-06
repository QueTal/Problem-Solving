#include <iostream>

using namespace std;

int n, k;
int weights[101], values[101];
int dp[101][100001];

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (j - weights[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}