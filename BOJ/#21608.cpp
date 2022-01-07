#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> prefer[401];
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int board[21][21];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    int a, b, c, d, e;
    for (int i = 0; i < N*N; i++){
        int prefer_cnt = -1, blank = -1, row = 0, col = 0;
        cin >> a >> b >> c >> d >> e;

        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                int tprefer = 0, tblank = 0;
                // 이미 차있으면 패스
                if (board[j][k] != 0) continue;
                
                // 상하좌우 확인
                for (int dd = 0; dd < 4; dd++){
                    int nr = j+dir[dd][0], nc = k+dir[dd][1];
                    if (nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
                    if (board[nr][nc] == 0) tblank++;
                    else {
                        if (board[nr][nc] == b) tprefer++;
                        if (board[nr][nc] == c) tprefer++;
                        if (board[nr][nc] == d) tprefer++;
                        if (board[nr][nc] == e) tprefer++;
                    }
                }

                // 1번 조건 : 좋아하는 학생이 많은 칸 찾기
                if (tprefer > prefer_cnt) {
                    row = j; col = k; blank = tblank; prefer_cnt = tprefer;
                }
                // 2번 조건 : 여러 개면 인접 칸 중 빈 칸이 많은 자리
                else if (tprefer == prefer_cnt and blank < tblank) {
                    row = j; col = k; blank = tblank;
                }
            }
        }

        board[row][col] = a;
        prefer[a].push_back(b);
        prefer[a].push_back(c);
        prefer[a].push_back(d);
        prefer[a].push_back(e);
    }
    
    int answer = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int cnt = 0;
            for (int k = 0; k < 4; k++){
                int nr = i+dir[k][0], nc = j+dir[k][1];
                if (nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
                if (prefer[board[i][j]].end() != find(prefer[board[i][j]].begin(), prefer[board[i][j]].end(), board[nr][nc])) cnt++;
            }
            if (cnt == 1) answer += 1;
            else if (cnt == 2) answer += 10;
            else if (cnt == 3) answer += 100;
            else if (cnt == 4) answer += 1000;
        }
    }

    cout << answer;
    return 0;
}