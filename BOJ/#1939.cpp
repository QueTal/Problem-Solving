#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 1000001

int n, m, start, finish;
bool visited[MAX];
vector< pair<int, int> > v[MAX];

bool bfs(int weight){
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        int cur = q.front(); q.pop();

        if (finish == cur) return true;
        // visited[cur] = true;

        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            if (!visited[next] and v[cur][i].second >= weight) {q.push(next); visited[next] = true;}
        }
    }
    return false;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    int a, b, w;
    int lo = 0, hi = 0;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> w;
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
        hi = max(hi, w);
    }
    
    cin >> start >> finish;
    while (lo <= hi){
        memset(visited, false, sizeof(visited)); 
        int mid = lo + (hi - lo) / 2;
        if (bfs(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    cout << hi;
    return 0;
}