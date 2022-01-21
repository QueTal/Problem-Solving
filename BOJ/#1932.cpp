#include <iostream>
#include <algorithm>

using namespace std;

int map[500][500], dp[500][500];
int N;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            cin >> map[i][j];
            dp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < N-1; i++){
        for (int j = 0; j <= i; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + map[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + map[i+1][j+1]);
        }
    }

    cout << *max_element(dp[N-1], dp[N-1]+N);
    return 0;
}