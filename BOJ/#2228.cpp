#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MIN -3276800

int arr[101] = {0}, dp[101][51] = {0};
int N, M;

int solve(int n, int m){
    if (m == 0) return 0;
    if (n <= 0) return MIN;
    if (dp[n][m] != -1) return dp[n][m];

    int sum = 0;
    dp[n][m] = solve(n-1, m);
    for (int i = n; i > 0; i--){
        sum += arr[i];
        int temp = solve(i-2, m-1) + sum;
        dp[n][m] = max(dp[n][m], temp);
    }
    return dp[n][m];
}

int main(void){
    cin.tie(0); 
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    cout << solve(N, M);
    
    return 0;
}