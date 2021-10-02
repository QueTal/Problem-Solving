#include <iostream>

using namespace std;
int n, dp[1000001];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if (i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout << dp[n];
    return 0;
}