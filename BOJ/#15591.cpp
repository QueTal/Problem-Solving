#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector< pair<int, int> > v[5001];

int bfs(int k, int vv){
    queue<int> q;
    vector<bool> visited(5001, false);
    int cnt = 0;
    
    q.push(vv);
    visited[vv] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first, usado = v[cur][i].second;
            if (!visited[next] and k <= usado){
                visited[next] = true;
                ++cnt;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;


    for(int i = 1; i < n; i++){
        int f, e, vv;
        cin >> f >> e >> vv;
        v[f].push_back(make_pair(e, vv));
        v[e].push_back(make_pair(f, vv));
    }
    
    for(int i = 0; i < m; i++){        
        int k, v;
        cin >> k >> v;
        cout << bfs(k, v) << endl;
    }

    return 0;
}