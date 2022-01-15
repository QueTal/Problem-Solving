#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> adj[2001];
bool visited[2001];

bool dfs(int node, int cnt){
    if (cnt == 5) return true;

    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++){
        if (visited[adj[node][i]]) continue;
        if (dfs(adj[node][i], cnt+1)) return true;
    } 
    visited[node] = false;
    return false;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < N; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        if (dfs(i, 1)) { cout << "1"; return 0; }
    }
    cout << "0";
    return 0;
}