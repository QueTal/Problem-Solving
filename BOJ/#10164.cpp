#include <iostream>

using namespace std;

int N, M, K;
int arr[16][16];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    if (K == 0) {
        for (int i = 0; i < M; i++) arr[0][i] = 1;
        for (int i = 0; i < N; i++) arr[i][0] = 1;

        for (int i = 1; i < N; i++){
            for (int j = 1; j < M; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        cout << arr[N-1][M-1];
    }
    else {
        int row = (K-1) / M, col = K % M -1;
        if (col == -1) col += M;
        
        for (int i = 0; i <= row; i++) arr[i][0] = 1;
        for (int i = 0; i <= col; i++) arr[0][i] = 1;

        for (int i = 1; i <= row; i++){
            for (int j = 1; j <= col; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }

        for (int i = row+1; i < N; i++) arr[i][col] = 1;
        for (int i = col+1; i < M; i++) arr[row][i] = 1;

        for (int i = row+1; i < N; i++){
            for (int j = col+1; j < M; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        cout << arr[row][col] * arr[N-1][M-1];
    }

    return 0;
}