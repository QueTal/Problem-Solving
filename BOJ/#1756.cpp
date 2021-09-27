#include <iostream>

using namespace std;

int n, m;
int pizza[300001], fire[300001];
int pos;

int bisearch(int target, int lo, int hi){
    while (lo <= hi){
        int mid = (hi + lo) / 2;
        if (fire[mid] >= target) {pos = mid; lo = mid + 1;}
        else hi = mid - 1;
    }
    return pos;
}

void solve() {
    int lo = 0, hi = n-1;
    pos = n;
    for(int i = 0; i < m; i++){
        hi = bisearch(pizza[i], lo, hi)-1;
        if (hi == -1 or hi == n-1) {
            pos = -1;
            break;
        }
    }
    cout << pos + 1;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> fire[i];
    for (int j = 0; j < m; j++) cin >> pizza[j];
    
    for (int i = 1; i < n; i++) fire[i] = min(fire[i], fire[i-1]);

    solve();
    return 0;
}