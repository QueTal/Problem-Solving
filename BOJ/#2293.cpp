#include <iostream>

using namespace std;
int n, k;
int coins[101], dp[10001];

int main(void){
    cin >> n >> k;
    for (int i  = 0; i  < n; i++) cin >> coins[i];

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= k; j++){
            if (dp[j - coins[i]]) dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k];
    return 0;
}