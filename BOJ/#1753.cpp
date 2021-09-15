#include <iostream>

using namespace std;
int arr[20001][20001];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int v, e, start;
    cin >> v >> e >> start;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            arr[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    for (int i = 0; i < e; i++){
        int f, t, w;
        cin >> f >> t >> w;
        arr[f-1][t-1] = min(w, arr[f-1][t-1]);
    }

    dijkstra();
}