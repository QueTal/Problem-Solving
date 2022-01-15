#include <iostream>

using namespace std;

int dp[4001][4001];

int main(void){
    string a, b;
    int m = 0;

    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++){
        for (int j = 1; j <= b.size(); j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                m = max(m, dp[i][j]);
            }
        }
    }
    cout << m;
    return 0;
}