#include <iostream>
#include <queue>

using namespace std;

int n, m, answer = 0;
int map[101][101] = {0}, visited[101][101] = {0};
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void outside(){
    queue< pair<int, int> > q;

    q.push(make_pair(0,0));

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();

        if (visited[r][c] == 1) continue;
        visited[r][c] = 1;
        map[r][c] = 2;

        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= n or nc >= m or nr < 0 or nc < 0) continue;
            if (map[nr][nc] == 0 or map[nr][nc] == 2) q.push(make_pair(nr, nc));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 0;
        }
    }
}

bool cheeseExist(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 1) return true;
        }
    }
    return false;
}

void find(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 1){
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int r = i + dir[k][0], c = j + dir[k][1];
                    if (r >= n or c >= m or r < 0 or c < 0) continue;
                    if (map[r][c] == 2) cnt++;
                }
                if (cnt > 1) map[i][j] = -1;
            }
        }
    }
}

void melt(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == -1) map[i][j] = 0;
        }
    }
}

void solve(){
    while (cheeseExist()) {
        outside();
        find();
        melt();
        answer++;
    } 
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    solve();
    cout << answer;
    return 0;
}