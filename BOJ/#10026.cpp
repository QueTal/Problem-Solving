#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, a = 0, b = 0;
vector<string> v;
int visited[101][101] = {0};
int dir[4][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

int dfs(){
    stack< pair<int,int> > st;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (!visited[i][j]){
                cnt++;
                st.push(make_pair(i, j));
                while(!st.empty()){
                    int r = st.top().first, c = st.top().second;
                    st.pop();

                    visited[r][c] = 1;

                    for(int k = 0; k < 4; k++){
                        int nr = dir[k][0] + r, nc = dir[k][1] + c;
                        if (nr >= n or nc >= n or nr < 0  or nc < 0) continue;
                        if (!visited[nr][nc] and v[r][c] == v[nr][nc]) st.push(make_pair(nr, nc));
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (v[i][j] == 'R') v[i][j] = 'G';
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
        string val;
        cin >> val;
        v.push_back(val);
    }
    a = dfs();
    b = dfs();
    cout << a << " " << b << endl;
    return 0;
}