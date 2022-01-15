#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0;
vector<int> adj[101];
bool visited[101];

void dfs(int node){
    cnt++;
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++){
        if (visited[adj[node][i]]) continue;
        dfs(adj[node][i]);
    }
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
    dfs(1);
    cout << cnt-1;
    return 0;
}