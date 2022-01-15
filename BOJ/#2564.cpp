#include <iostream>

using namespace std;
int R, C, T;
int cnt[101];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;
    cin >> T;

    int x, y;
    for (int i = 0; i < T+1; i++){
        cin >> x >> y;
        if (x == 1) cnt[i] = y;
        else if (x == 4) cnt[i] = R+y;
        else if (x == 2) cnt[i] = R+C+R-y;
        else cnt[i] = R+C+R+C-y;
    }
    
    int answer = 0;
    for (int i = 0; i < T; i++){
        int a = abs(cnt[T] - cnt[i]);
        answer += min(a, 2*(R+C)-a);
    }
    cout << answer;
    return 0;
}