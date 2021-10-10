#include <string>
#include <vector>
#define INF 20000000

using namespace std;
int dist[200][200] = {0};

void floyd (int n){
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = i == j ? 0 : INF;
        }
    }
    for(auto fare: fares){
        dist[fare[0]-1][fare[1]-1] = fare[2];
        dist[fare[1]-1][fare[0]-1] = fare[2];
    }
    
    floyd(n);
    
    s--; b--; a--;
    
    for(int i = 0; i < n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}