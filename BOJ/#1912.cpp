#include <iostream>

using namespace std;

int N, m;
int arr[1000001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    m = arr[0];
    for (int i = 1; i < N; i++) {
        arr[i] = max(arr[i], arr[i-1]+arr[i]);
        m = max(m, arr[i]);
    }
    cout << m;
    return 0;
}