#include <iostream>

using namespace std;

int n;
int arr[2] = {0};
int dp[2][41] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[0][0] = 1;
    dp[1][1] = 1;
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        for (int j = 2; j < 41; j++){
            dp[0][j] = dp[0][j-1] + dp[0][j-2];
            dp[1][j] = dp[1][j-1] + dp[1][j-2];
        }
        cout << dp[0][val] << " " << dp[1][val] << endl;
    }
    return 0;
}