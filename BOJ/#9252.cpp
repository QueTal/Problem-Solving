#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string a, b;

int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);

    cin >> a >> b;
    vector< vector<int> > v(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1]+1;
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    cout << v[a.size()][b.size()] << endl;

    string answer = "";
    int i = a.size(), j = b.size();
    while (1) {
        if (v[i][j] == 0) break;
        if (v[i][j] == v[i-1][j]) i--;
        else if (v[i][j] == v[i][j-1]) j--;
        else {
            i--; j--;
            answer += a[i];
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}