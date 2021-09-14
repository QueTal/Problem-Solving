#include <iostream>
#include <vector>

using namespace std;

int n, M = -1000000000, m = 1000000000;
int nums[12]={0}, ops[4]={0};

void calc(int cur, int cnt){
    if (cnt == n){
        M = max(cur, M);
        m = min(cur, m);
        return;
    }

    for(int i = 0; i < 4; i++){
        if (ops[i] == 0) continue;
        ops[i]--;
        if (i == 0) calc(cur + nums[cnt], cnt + 1);
        else if (i == 1) calc(cur - nums[cnt], cnt + 1);
        else if (i == 2) calc(cur * nums[cnt], cnt + 1);
        else if (i == 3) calc(cur / nums[cnt], cnt + 1);
        ops[i]++;
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> ops[i];
    }

    calc(nums[0], 1);
    cout << M << endl;
    cout << m << endl;
    return 0;
}