#include <iostream>
#include <stack>

using namespace std;
int n, answer = 1;
int map[101][101] = {0}, visited[101][101] = {0};
int dir[4][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

int dfs(int rain){
    int cnt = 0;
    stack< pair<int, int> > st;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (!visited[i][j] and rain < map[i][j]){
                cnt++;
                st.push(make_pair(i, j));
                while(!st.empty()){
                    int r = st.top().first, c = st.top().second;
                    st.pop();

                    visited[r][c] = 1;

                    for(int k = 0; k < 4; k++){
                        int nr = dir[k][0] + r, nc = dir[k][1] + c;
                        if (nr >= n or nc >= n or nr < 0  or nc < 0) continue;
                        if (!visited[nr][nc] and rain < map[nr][nc]) st.push(make_pair(nr, nc));
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    return cnt;
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
    int rain = 1;
    while(1){
        int val = dfs(rain++);
        if (val == 0) break;
        answer = max(answer, val);
    }
    cout << answer << endl;
    return 0;
}