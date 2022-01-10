#include <iostream>
#include <cstring>

using namespace std;

int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int T, M, N, K;
bool visited[51][51];
int ground[51][51];

void dfs(int r, int c){
    if (r < 0 or r >= N or c < 0 or c >= M or visited[r][c]) return;

    visited[r][c] = true;
    for (int i = 0; i < 4; i++){
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr < 0 or nr >= N or nc < 0 or nc >= M) continue;
        if (ground[nr][nc]) dfs(nr, nc);
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int test_case = 0; test_case < T; test_case++){
        int cnt = 0;
        cin >> M >> N >> K;

        memset(visited, false, sizeof(visited));
        memset(ground, 0, sizeof(ground));

        int x, y;
        for (int i = 0; i < K; i++){
            cin >> x >> y;
            ground[y][x] = 1;
        }   

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (ground[i][j] and !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }   
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}