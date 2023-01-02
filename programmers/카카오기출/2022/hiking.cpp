#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool isSummit(int cur, vector<int>& summits){
    for (auto summit: summits){
        if (cur == summit) return true;
    }
    return false;
}

void bfs(vector<int>& gates, vector<int>& summits, unordered_map<int, vector<vector<int>>>& paths, vector<int>& dist){
    queue<int> q;
    
    for (auto gate: gates) q.push(gate);
    
    while (!q.empty()){
        int cur = q.front(); q.pop();
        
        if (isSummit(cur, summits)) continue;
        
        // compare dist
        for (auto path : paths[cur]){
            int next = path[0], intensity = path[1];    
            if (dist[next] > max(dist[cur], intensity)){
                dist[next] = max(dist[cur], intensity);
                q.push(next);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> dist(n+1, 10000001);
    unordered_map<int, vector<vector<int>>> new_path;
    
    for (auto path : paths){
        new_path[path[0]].push_back({path[1], path[2]});
        new_path[path[1]].push_back({path[0], path[2]});
    }
    
    // bfs
    for (auto gate: gates) dist[gate] = 0;
    
    bfs(gates, summits, new_path, dist);
    
    // compare
    int min_dist = 987654321, min_summit = -1;
    for (auto summit: summits){
        if (dist[summit] < min_dist){
            min_dist = dist[summit];
            min_summit = summit;
        }
        else if (dist[summit] == min_dist and min_summit > summit){
            min_summit = summit;
        }
    }   

    return {min_summit, min_dist};
}