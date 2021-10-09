#include <iostream>
#include <cstdio>

using namespace std;
int n, m;
int arr[100001];

int main(void){
    scanf("%d%d", &n, &m);
    arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        int A;
        cin >> A;
        arr[i] = arr[i-1] + A;
    }

    for (int i = 0; i < m; i++){
        int from, to;
        scanf("%d%d", &from, &to);
        printf("%d\n", arr[to]-arr[from-1]);
    }
    return 0;
}