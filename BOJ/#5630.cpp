#include <iostream>

using namespace std;

int arr[10000];

void pre2post(int s, int e){
    if (s >= e) return;
    else if (s == e-1){
        cout << arr[s] << "\n";
        return;
    }
    int idx = s+1;
    for (; idx < e; idx++){
        if (arr[s] < arr[idx]) break;
    }
    pre2post(s+1, idx);
    pre2post(idx, e);
    cout << arr[s] << "\n";
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int idx = 0, num;
    
    while (cin >> num){
        arr[idx++] = num;
    } 

    pre2post(0, idx);
    return 0;
}