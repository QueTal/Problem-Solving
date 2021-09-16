#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int map[21][21] = {0}, visited[21][21] = {0};
int n, answer = 0, size = 2;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int getDist(int fromX, int fromY, int toX, int toY){
    queue< pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(fromX, fromY), 0));

    while(!q.empty()){
        int r = q.front().first.first, c = q.front().first.second, d = q.front().second;
        q.pop();
        if (visited[r][c]) continue;
        if (toX == r and toY == c) return d;
        
        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= n or nc >= n or nr < 0 or nc < 0) continue;
            if (map[nr][nc] <= size) q.push(make_pair(make_pair(nr, nc), d + 1));
        }
    }
    return 0;
}

void initVisited() {
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
}

void bfs(){
    queue< pair<pair<int, int>, int> > q;
    int eat = 0, row, col;

    // 아기 상어 위치 찾기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (map[i][j] == 9) {
                q.push(make_pair(make_pair(i, j),0));
                row = i; col = j;
                map[i][j] = 0;
                break;
            }
        }
    }

    while(!q.empty()){
        int r = q.front().first.first, c = q.front().first.second, d = q.front().second;
        q.pop();
        
        if (row != r or col != c) eat++;
        if (eat == size) {
            eat = 0;
            size++;
        }
        
        answer += d;
        row = r; col = c;

        int dd = n*n;
        pair<int, int> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if ((i != row or j != col) and map[i][j] != 0 and map[i][j] < size){
                    int temp = getDist(row, col, i, j);
                    initVisited();
                    if (temp != 0 and temp < dd) { dd = temp; res.first = i; res.second = j; }
                }
            }
        }
        if (dd != n*n) {
            q.push(make_pair(res, dd)); 
            map[res.first][res.second] = 0;
        }
    }

    cout << answer;
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    bfs();
    return 0;
}