#include <iostream>

using namespace std;

int n, m, answer = 0;
char board[21][21];
int alpha[26] = {0};

void dfs(int r, int c, int cnt){
    if (alpha[board[r][c] - 'A'] > 0) {
        answer = max(answer, cnt); 
        return;
    }

    alpha[board[r][c] - 'A']++;
    if (r+1 < n) dfs(r+1, c, cnt+1);
    if (c+1 < m) dfs(r, c+1, cnt+1);
    if (r-1 >= 0) dfs(r-1, c, cnt+1);
    if (c-1 >= 0) dfs(r, c-1, cnt+1);

    alpha[board[r][c]-'A'] = 0;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    dfs(0,0,1);
    cout << answer-1 << endl;
    return 0;
}