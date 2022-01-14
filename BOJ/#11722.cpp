#include <iostream>

using namespace std;

int dp[1001], input[1001];
int N;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> input[i];

    int m = 0;
    for (int i = 1; i <= N; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (input[i] < input[j] and dp[i] < dp[j]+1) dp[i] = dp[j]+1;
        }
        m = max(m, dp[i]);
    }

    cout << m;
    return 0;
}