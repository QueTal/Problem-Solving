#include <iostream>

using namespace std;

long long arr[501][501];
int N, M, W, T;

bool floyd(){
    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                    if (i==j and  arr[i][j] < 0) return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while (T--){
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (i == j) arr[i][j] = 0;
                else arr[i][j] = 1987654321;
            }
        }

        long long s, e, t;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            arr[s][e] = min(arr[s][e], t);
            arr[e][s] = min(arr[e][s], t);
        }

        for (int i = 0; i < W; i++){
            cin >> s >> e >> t;
            arr[s][e] = min(arr[s][e], -t);
        }

        if (floyd()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}