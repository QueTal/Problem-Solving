#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int dist[20001] = {0};

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int v, e, start;
    cin >> v >> e;
    cin >> start;
    
    vector< vector < pair<int, int> > > vv(v+1);

    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vv[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++) dist[i] = INF;
    dist[start] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()){
        int node = pq.top().second;
        int val = -pq.top().first;
        pq.pop();

        for (auto n : vv[node]){
            int next = n.first;
            int nextVal = val + n.second;
            if (nextVal < dist[next]){
                dist[next] = nextVal;
                pq.push(make_pair(-nextVal, next));
            }
        }
    }
    
    for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
    return 0;
}