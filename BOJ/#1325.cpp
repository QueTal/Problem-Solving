#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;
vector<int> trust[10001];
bool visited[10001];

void dfs(int cur){
    visited[cur] = true;
    cnt++;

    for (int i = 0; i < trust[cur].size(); i++){
        if (visited[trust[cur][i]]) continue;    
        dfs(trust[cur][i]);
    }
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int x, y;
    while (M--){
        cin >> x >> y;
        trust[y].push_back(x);
    }

    vector<int> check;
    int m = -1;
    for (int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        dfs(i);
        if (m == cnt) check.push_back(i);
        else if (m < cnt){
            m = cnt;
            check.clear();
            check.push_back(i);
        }
    }

    sort(check.begin(), check.end());
    
    for (int i = 0; i < check.size(); i++) cout << check[i] << " ";
    return 0;
}