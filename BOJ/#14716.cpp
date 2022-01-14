#include <iostream>

using namespace std;

int arr[251][251];
int M, N;
bool visited[251][251];
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(int r, int c){
    visited[r][c] = true;
    for (int i = 0; i < 8; i++){
        int nr = r+dir[i][0], nc = c+dir[i][1];
        if (nr < 0 or nr >= M or nc < 0 or nc >= N or arr[nr][nc] != 1 or visited[nr][nc]) continue;
        dfs(nr, nc);
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (!visited[i][j] and arr[i][j] == 1){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}