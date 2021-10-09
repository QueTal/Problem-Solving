#include <iostream>

using namespace std;

int n, m;
int arr[1001][1001], dp[1001][1001], rl[2][1001][1001];
int dir[3][2] = {{0,1}, {0,-1}, {1,0}};


int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);

    cin >> n >> m;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    // 1행 해결
    for(int j = 1; j < m; ++j){
        dp[0][j] += dp[0][j-1] + arr[0][j];
    }

    // 나머지 행
    for (int i = 1; i < n; i++){
        // 왼쪽
        rl[0][i][0] = arr[i][0] + dp[i-1][0];
        for(int j = 1; j < m; j++){
            rl[0][i][j] = max(dp[i-1][j], rl[0][i][j-1]) + arr[i][j];
        }
        
        // 오른쪽
        rl[1][i][m-1] = arr[i][m-1] + dp[i-1][m-1];
        for (int j = m-2; j >= 0; --j){
            rl[1][i][j] = max(dp[i-1][j], rl[1][i][j+1]) + arr[i][j];
        }

        // 비교 후 확정
        for (int j = 0; j < m; ++j) dp[i][j] = max(rl[0][i][j], rl[1][i][j]);
    }

    cout << dp[n-1][m-1];
    return 0;
}