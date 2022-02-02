#include <iostream>

using namespace std;

int N, M, R;
int items[101], maps[101][101];

void floyd(){
    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
            }
        }
    }
}

int check(){
    int answer = 0;

    for (int i = 1; i <= N; i++){
        int cnt = 0;
        for (int j = 1; j <= N; j++){
            if (maps[i][j] <= M) cnt += items[j];
        }
        answer = max(answer, cnt);
    }
    return answer;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) cin >> items[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++){
            if (i == j) maps[i][j] = 0;
            else maps[i][j] = 987654321;
        }
    }

    int x, y, c;
    for (int i = 0; i < R; i++){
        cin >> x >> y >> c;
        maps[x][y] = c;
        maps[y][x] = c;
    }

    floyd();
    cout << check();

    return 0;
}