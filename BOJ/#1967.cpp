#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

int N, M = -1, far = 0;
unordered_map<int, vector< pair<int, int> > > adj;
bool visited[10000];

void dfs(int cur, int cnt){
    visited[cur] = true;
    
    if (M < cnt) {
        M = cnt;
        far = cur;
    }
    for (int i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i].first, val = adj[cur][i].second;
        if (visited[next]) continue;
        dfs(next, cnt+val);
    }
    visited[cur] = false;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int x, y, val;
    for (int i = 0; i < N-1; i++){
        cin >> x >> y >> val;
        adj[x].push_back(make_pair(y, val));
        adj[y].push_back(make_pair(x, val));
    }
    
    dfs(1, 0);
    M = -1; memset(visited, false, sizeof(visited));
    dfs(far, 0);
    
    cout << M;
    return 0;
}