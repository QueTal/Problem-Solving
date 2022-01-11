#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int N, M;
int map[101][101], dist[101][101];

bool comp(vector<int>& a, vector<int>& b){
    if (a[2] == b[2]){
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    return a[2] < b[2];
}

int main(void){
    cin.tie(0); 
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    
    int x, y;
    for (int i = 0; i < M; i++){
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i == j) continue;
            dist[i][j] = map[i][j] == 1 ? 1 : INF;
        }
    }

    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector< vector<int> > v;
    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            int d = 0;
            for (int k = 1; k <= N; k++){
                d += min(dist[k][i], dist[k][j]) * 2;
            }
            vector<int> temp(3,0);
            temp[0] = i; temp[1] = j; temp[2] = d;
            v.push_back(temp);
        }
    }

    sort(v.begin(), v.end(), comp);
    cout << v[0][0] << " " << v[0][1] << " " << v[0][2];
    return 0;
}