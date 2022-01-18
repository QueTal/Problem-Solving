#include <iostream>

using namespace std;
int N;
int arr[1000][3], dp[1000][3];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++){
            if (j == 0) dp[i][j] = arr[i][j] + min(dp[i-1][1], dp[i-1][2]);
            else if (j == 1) dp[i][j] = arr[i][j] + min(dp[i-1][0], dp[i-1][2]);
            else dp[i][j] = arr[i][j] + min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
    return 0;
}