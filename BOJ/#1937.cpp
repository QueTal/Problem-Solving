#include <iostream>
#include <cstring>

using namespace std;

int n, ans = 1;
int dp[501][501], arr[501][501];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int solve(int r, int c){
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 1;

    for (int i = 0; i < 4; i++){
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr >= n or nc >= n or nr < 0 or nc < 0) continue;
        if (arr[r][c] < arr[nr][nc]) {
            
            dp[r][c] = max(dp[r][c], solve(nr, nc) + 1);
        }
    }
    ans = max(ans, dp[r][c]);
    return dp[r][c];
}

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){   
            if (dp[i][j] == -1) solve(i, j);
        }
    }
    cout << ans;

    return 0;
}