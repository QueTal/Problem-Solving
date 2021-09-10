#include <string>
#include <vector>
#include <iostream>

using namespace std;

void rotateKey(vector<vector<int>>& key){
    int n = key.size();
    
    for(int i = 0; i < n/2; i++){
        for(int j = i; j < n - i - 1; j++){
            int temp = key[i][j];
            
            key[i][j] = key[n-j-1][i];
            key[n-j-1][i] = key[n-i-1][n-j-1];
            key[n-i-1][n-j-1] = key[j][n-i-1];
            key[j][n-i-1] = temp;
        }
    }    
}

bool check(vector<vector<int>>& v, vector<vector<int>>& key, int row, int col, int m, int n){
    auto temp = v;
    
    for(int i = 0; i < key.size(); i++){
        for (int j = 0; j < key.size(); j++){
            temp[i + row][j + col] += key[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (temp[i + m - 1][j + m - 1] == 2 or temp[i + m - 1][j + m - 1] == 0) return false;
        }
    }
    return true;
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    vector<vector<int>> v (2*(m-1)+n, vector<int>(2*(m-1)+n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v[i+m-1][j+m-1] = lock[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++){
        rotateKey(key);
        for (int j = 0; j < v.size() - m + 1; j++){
            for(int k = 0; k < v.size() - m + 1; k++){
                if (check(v, key, j, k, m, n)) return true;
            }
        }
    }
    return false;
}