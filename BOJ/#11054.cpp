#include <iostream>

using namespace std;

int N, m = 0;
int arr[1001], l[1001], r[1001];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // from left
    for (int i = 0; i < N; i++){
        l[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                l[i] = max(l[i],  l[j]+1);
            }
        }
    }

    // from right 
    for (int i = N-1; i >= 0; i--){
        r[i] = 1;
        for (int j = N-1; j > i; j--){
            if (arr[i] > arr[j]) {
                r[i] = max(r[i], r[j]+1);
            }
        }
    }

    for (int i = 0; i < N; i++) m = max(m, l[i]+r[i]-1);
    
    cout << m;
    return 0;
}