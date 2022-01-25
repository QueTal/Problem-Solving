#include <iostream>
#include <queue>

using namespace std;

int N, M;
string arr[1001];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dp[1001][1001][2];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    queue< pair < pair<int, int>, int> > q;

    dp[0][0][0] = 1;
    q.push(make_pair(make_pair(0, 0), 0));
    int br;

    while (!q.empty()){
        int r = q.front().first.first, c = q.front().first.second;
        br = q.front().second;
        q.pop();

        if (r == N-1 and c == M-1) break;

        for (int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr < 0 or nr >= N or nc < 0 or nc >= M) continue;
            if (arr[nr][nc] == '0' and dp[nr][nc][br] == 0){
                dp[nr][nc][br] = dp[r][c][br]+1;
                q.push(make_pair(make_pair(nr, nc), br));
            }
            else if (br == 0) {
                dp[nr][nc][br+1] = dp[r][c][br]+1;
                q.push(make_pair(make_pair(nr, nc), 1));
            }
        }
    }
    dp[N-1][M-1][br] == 0 ? cout << -1 : cout << dp[N-1][M-1][br];
    
    return 0;
}