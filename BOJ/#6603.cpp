#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int arr[50];
bool isUsed[50];
int N;

void combo(int cnt, int idx, vector<int>& temp, vector< vector<int> >& ans){
    if (cnt == 6){
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < N; i++){
        if (isUsed[i]) continue;
        isUsed[i] = true;
        temp.push_back(arr[i]);
        combo(cnt+1, i+1, temp, ans);
        isUsed[i] = false;
        temp.pop_back();
    }
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    while (1){
        cin >> N;
        if (N == 0) break;
        memset(arr, 0, sizeof(arr));
        memset(isUsed, 0, sizeof(isUsed));

        for (int i = 0; i < N; i++) cin >> arr[i];
        vector<int> temp;
        vector< vector<int> > ans;
        combo(0, 0, temp, ans);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < 6; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}