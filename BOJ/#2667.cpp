#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> m;

int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(){
    queue< pair<int, int> > q;
    vector<int> v;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (m[i][j] == '1'){
                q.push(make_pair(i, j));
                m[i][j] = '0';

                int cnt = 0;
                while (!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();

                    m[cur.first][cur.second] = '0';
                    
                    cnt++;

                    for(int i = 0; i < 4; i++){
                        int nr = cur.first + dir[i][0], nc = cur.second + dir[i][1];
                        if (nr >= n or nr < 0 or nc >= n or nc < 0) continue;
                        if (m[nr][nc] == '1') {
                            q.push(make_pair(nr, nc)); 
                            m[nr][nc] = '0';
                        }
                    }
                }
                v.push_back(cnt);
            }
        }
    }

    // 출력
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (int vv : v) cout << vv << endl;
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++){
        string val;
        cin >> val;
        m.push_back(val);
    }

    bfs();
    return 0;
}
