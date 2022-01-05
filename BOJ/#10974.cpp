#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> v(N, 0);
    
    for (int i = 0; i < N; i++) v[i] = i+1;
    do {
        for (int i = 0; i < N; i++) cout << v[i] << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}