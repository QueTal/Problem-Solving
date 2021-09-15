#include <iostream>
#include <queue>

using namespace std;

int map[10][10] = {0}, visited[10][10] = {0}, temp[10][10] = {0};
int n, m, answer = -1;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void copy(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = map[i][j];
        }
    }
}

void bfs() {
    queue<pair<int, int> > q;
    copy();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if (visited[i][j] or temp[i][j] != 2) continue;
            
            q.push(make_pair(i,j));
            while(!q.empty()){
                int r = q.front().first, c = q.front().second;
                q.pop();

                if (visited[r][c]) continue;
                temp[r][c] = 2;
                visited[r][c] = 1;

                for (int i = 0; i < 4; i++){
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if (nr >= n or nc >= m or nr < 0 or nc < 0) continue;
                    if (temp[nr][nc] == 0 or temp[nr][nc] == 2) q.push(make_pair(nr,nc));
                }
            }          
        }
    }

    // 숫자 세기
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (temp[i][j] == 0) cnt++;
        }
    }

    // 초기화
    copy();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }
    // 값 갱신 
    answer = max(answer, cnt);
}

void solve(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 0) {
                map[i][j] = 1;
                solve(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i  = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    solve(0);
    cout << answer << endl;
    return 0;
}