#include <iostream>

using namespace std;
int N, K;
int money[11];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> money[i];

    int cnt = 0;
    for (int i = N-1; K != 0 or i >= 0; i--){
        if (money[i] > K) continue;
        else {
            cnt += K/money[i];
            K = K - (K/money[i])*money[i];
        }
    }
    cout << cnt;
    return 0;
}