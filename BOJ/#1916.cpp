#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dist[1001];
vector< pair<int, int> > v[1001];

void dijkstra(int start){
    priority_queue< pair<int, int> > pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()){
        int cost = -pq.top().first, cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;
        
        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first, temp = cost + v[cur][i].second;
            if (temp < dist[next]) {
                dist[next] = temp;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    int x, y, val;
    for (int i = 0; i < M; i++){
        cin >> x >> y >> val;
        v[x].push_back(make_pair(y, val));
    }
    
    int from, to;
    cin >> from >> to;
    
    for (int i = 1; i <= N; i++) dist[i] = 987654321;
    dijkstra(from);

    cout << dist[to];

    return 0;
}