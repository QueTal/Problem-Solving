#include <iostream>

using namespace std;

int answer = 9999999, n, m, h;
bool visited[11][31] = {false};

bool start(){
    for(int i = 1; i <= n; i++){
        int cur = i;
        for(int j = 1; j <= h; j++){
            if (visited[cur][j]) cur = cur + 1;
            else if (visited[cur-1][j]) cur = cur - 1;
        }
        if (cur != i) return false;
    }
    return true;
}

void select(int cnt, int row) {
    if (cnt > 3) return;

    if (start()){
        answer = min(answer, cnt);
        return;
    }
    // 한줄 씩 놓아보기
    for (int i = row; i <= h; i++){
        for(int j = 1; j < n; j++){
            if (visited[j][i]) continue;
            if (visited[j-1][i]) continue;
            if (visited[j+1][i]) continue;

            visited[j][i] = true;
            select(cnt+1, i);
            visited[j][i] = false;
        }
    }
}

void solve(){
    select(0, 1);
    if (answer == 9999999) answer = -1;
    cout << answer;
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        visited[b][a] = true;
    }
    solve();
    return 0;
}