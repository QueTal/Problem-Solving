#include <iostream>
#include <queue>

using namespace std;

int N, M, day = 0;
int box[1001][1001];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue< pair<int, int> > q;

void bfs(){
    while (!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr < 0 or nr >= M or nc < 0 or nc >= N) continue;
            if (box[nr][nc] == 0) {
                box[nr][nc] = box[r][c] + 1;
                day = max(day, box[nr][nc]);
                q.push(make_pair(nr,nc));
            }
        }
    }
}

bool check(){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (box[i][j] == 0) return false; 
        }
    }
    return true;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> box[i][j];
            if (box[i][j] == 1) q.push(make_pair(i,j));
        }
    }
    
    bfs();
    if (!check()) cout << -1;
    else day == 0 ? cout << day : cout << day-1;

    return 0;
}