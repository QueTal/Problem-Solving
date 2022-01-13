#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> up;
bool visited[1000001];

void make(int cur, vector<int> v[]){
    visited[cur] = true;
    for (int i = 0; i < v[cur].size(); i++){
        if (visited[v[cur][i]]) continue;
        up[v[cur][i]] = cur;
        make(v[cur][i], v);
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    vector<int> adj[N+1];
    int x, y;
    for (int i; i < N-1; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    make(1, adj);

    // up에서 찾기
    for (int i = 2; i <= N; i++) cout << up[i] << "\n";
    return 0;
}