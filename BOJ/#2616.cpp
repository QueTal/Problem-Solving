#include <iostream>

using namespace std;

int n, m, ans = 0;
int arr[50001] = {0}, dp[4][50001] = {0};

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    cin >> m;

    for (int i = 1; i <= 3; i++){
        for (int j = i * m; j <= n; j++){
            if (i == 1) dp[i][j] = max(dp[i][j-1], arr[j] - arr[j-m]);
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + arr[j] - arr[j-m]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}