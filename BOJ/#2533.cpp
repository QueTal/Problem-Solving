#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> e[1000001];
bool visited[1000001];
int dp[1000001][2]; // 0: not, 1: early

void find(int x){
    visited[x] = true;

    dp[x][0] = 1;
    for (int i = 0; i < e[x].size(); i++){
        int child = e[x][i];
        if (visited[child]) continue;
        find(child);
        dp[x][1] += dp[child][0];
        dp[x][0] += min(dp[child][1], dp[child][0]);
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int u, v;
    for (int i = 0; i < N-1;i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    find(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}