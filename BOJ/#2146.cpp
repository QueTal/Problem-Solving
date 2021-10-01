#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, cnt = 2, ans = 10000000;
int map[101][101], dist[101][101];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int r, int c){
    map[r][c] = cnt;
    for(int i = 0; i < 4; i++){
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr >= n or nc >= n or nr < 0 or nc < 0) continue;
        if (map[nr][nc] == 1) dfs(nr, nc);
    }
}

void bfs(int k){
    queue<pair<int, int> > q;

    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (map[i][j] == k){
                q.push(make_pair(i,j));
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()){ 
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++){
            int r = cur.first + dir[i][0], c = cur.second + dir[i][1];
            if (r >= n or c >= n or r < 0 or c < 0) continue;

            if (map[r][c] and map[r][c] != k){
                if (ans > dist[cur.first][cur.second])
                    ans = dist[cur.first][cur.second];
                return;
            }

            if (!map[r][c] and dist[r][c] == -1){
                dist[r][c] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(r, c));
            }
        }
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (map[i][j] == 1) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << endl;
    for (int i = 1; i < cnt; i++) bfs(i);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans;
    return 0;
}