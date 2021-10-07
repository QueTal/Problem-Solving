#include <iostream>

using namespace std;

int n, m;
int city[101][101];

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n ; j++)
            city[i][j] = i==j ? 0 : 10000000;
    
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        city[from-1][to-1] = min(city[from-1][to-1], cost);
    }

    for (int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << city[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}