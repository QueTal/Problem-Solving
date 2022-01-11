#include <iostream>
#include <queue>

using namespace std;

int N,M,H;
int box[101][101][101];
bool visited[101][101][101];
int dir[6][3] = {{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1}};

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    queue< vector<int> > q;
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> box[i][j][h];
                if (box[i][j][h] == 1) {
                    vector<int> temp(3, 0);
                    temp[0] = i; temp[1] = j; temp[2] = h;
                    q.push(temp);
                    visited[i][j][h] = true;
                }
            }
        }
    }

    int cnt = 0;
    while (!q.empty()){
        int r = q.front()[0], c = q.front()[1], h = q.front()[2];
        q.pop();

        for (int i = 0; i < 6; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1], nh = h + dir[i][2];
            if (nr < 0 or nr >= N or nc < 0 or nc >= M or nh < 0 or nh >= H) continue;
            if (!visited[nr][nc][nh] and box[nr][nc][nh] == 0) {
                visited[nr][nc][nh] = true;
                box[nr][nc][nh] = box[r][c][h] + 1;
                cnt = max(cnt, box[nr][nc][nh]);
                vector<int> temp(3,0);
                temp[0] = nr; temp[1] = nc; temp[2] = nh;
                q.push(temp);
            }
        }
    }

    // check
    for (int h = 0; h < H; h++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (box[i][j][h] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cnt == 0 ? cout << "0" : cout << cnt-1;
    return 0;
}