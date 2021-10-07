#include <iostream>

using namespace std;

int n, dp[1001] = {0}, arr[1001] = {0};

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans;
    return 0;
}