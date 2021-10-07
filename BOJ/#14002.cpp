#include <iostream>
#include <vector>

using namespace std;

int n, dp[1001] = {0}, arr[1001] = {0};

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector< vector<int> > v(n, vector<int>());

    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if (arr[i] > arr[j] and dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                v[i] = v[j];
                v[i].push_back(arr[i]);
            }
        }
        if (v[i].size() == 0) v[i].push_back(arr[i]);
    }
    int ans = -1, size = -1;
    for (int i = 0; i < n; i++) {
        if (size < dp[i]) { ans = i; size = dp[i]; }
    }

    cout << dp[ans] << endl;
    for(int i = 0; i < dp[ans]; i++) cout << v[ans][i] << " ";

    return 0;
}