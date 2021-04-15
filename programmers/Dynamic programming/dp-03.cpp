/* 
 *
 * 
 */

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0, mod = 1e9+7;
    vector<vector<int>> v(n, vector<int>(m, 1));
    
    for(auto puddle : puddles) v[puddle[1]-1][puddle[0]-1] = 0;

    for(int i = 1; i < m; i++){
        if(v[0][i] == 0){
            for(int j = i; j < m; j++) v[0][j] = 0;
            break;
        }
    }
    for(int i = 1; i < n; i++){
        if(v[i][0] == 0){
            for(int j = i; j < n; j++) v[j][0] = 0;
            break;
        }
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(v[i][j] == 0) continue;
            v[i][j] = (v[i-1][j] + v[i][j-1]) % mod;
        }
    }
    return v[n-1][m-1];
}