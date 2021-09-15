#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> map;
int n, m;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
bool visited[101][101] = {false};

void bfs() {
    queue< pair< pair<int, int>, int> > q;
    
    q.push(make_pair(make_pair(0,0), 1));
    visited[0][0] = true;

    while (!q.empty()){
        int r = q.front().first.first, c = q.front().first.second, cnt = q.front().second;
        q.pop();
        
        if (r == n-1 and c == m-1) {cout << cnt << endl; return;}
        
        for (int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= n or nc >= m or nr < 0 or nc < 0) continue;
            if (!visited[nr][nc] and map[nr][nc] == '1') {
                q.push(make_pair(make_pair(nr, nc), cnt+1));
                visited[nr][nc] = true;
            }
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string val;
        cin >> val;
        map.push_back(val);
    }

    bfs();
    
    return 0;
}
