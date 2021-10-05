#include <iostream>

using namespace std;

int map[1001][1001] = {0};
int n, m;

void solve(){
    for(int i = 1; i < n; i++) map[i+1][1] += map[i][1];
    for(int i = 1; i < m; i++) map[1][i+1] += map[1][i];

    for (int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++) {
            map[i][j] = map[i][j] + max(map[i-1][j], map[i][j-1]);
        }
    }
}

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    
    solve();
    
    cout << map[n][m];
    
    return 0;
}