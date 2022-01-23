#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, far = 0, M = -1;
bool visited[100001];
unordered_map<int, vector< pair<int, int> > > adj;

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

    for (int i = 0; i < N; i++){
        int from, to = 0, val;
        cin >> from;

        while (1){
            cin >> to;
            if (to == -1) break;
            cin >> val;
            adj[from].push_back(make_pair(to, val));
        }
    }
    
    dfs(1, 0); dfs(far, 0);
    
    cout << M;
    return 0;
}