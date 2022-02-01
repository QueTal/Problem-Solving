#include <iostream>

using namespace std;

int N, M, X;
int arr[1001][1001];

void floyd(){
    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = 987654321;
        }
    }

    for (int i = 0; i < M; i++){
        int a, b, val;
        cin >> a >> b >> val;
        arr[a][b] = val;
    }

    floyd();

    int m = -1;

    for (int i = 1; i <= N; i++){
        m = max(m, arr[i][X]+arr[X][i]);
    }
    cout << m;
    return 0;
}