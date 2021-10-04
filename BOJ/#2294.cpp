#include <iostream>

using namespace std;

int n, k;
int coins[101], dp[10001]={0};

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    for(int i = 1; i <= k; i++) dp[i] = 10001;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];

        for (int j = coins[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if (dp[k] == 10001) cout << -1 << endl;
    else cout << dp[k] << endl;

    return 0;
}