#include <iostream>

using namespace std;

int n, m;
int tall[501][501];

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n ; j++)
            tall[i][j] = i==j ? 0 : 10000000;
    
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        tall[from-1][to-1] = 1;
        tall[to-1][from-1] = -1;
    }

    for (int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (tall[i][k] == 1 and tall[k][j] == 1) tall[i][j] = 1;
                if (tall[i][k] == -1 and  tall[k][j] == -1) tall[i][j] = -1;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if (tall[i][j] != 10000000 and tall[i][j] != 0) cnt++;
        }
        if (cnt == n-1) answer++;    
    }
    cout << answer;

    return 0;
}