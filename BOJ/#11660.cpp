#include <cstdio>

using namespace std;

int arr[1025][1025] = {0};
int n, m;

int main(void){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 2; i <= n; i++) arr[i][1] += arr[i-1][1];
    for (int i = 2; i <= n; i++) arr[1][i] += arr[1][i-1];

    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= n; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] + arr[i][j] - arr[i-1][j-1];
        }
    }
    
    for(int i = 0; i < m; i++){
        int fs, fe, ts, te;
        scanf("%d %d %d %d", &fs, &fe, &ts, &te);
        printf("%d\n", arr[ts][te] + arr[fs-1][fe-1] - (arr[ts][fe-1] + arr[fs-1][te]));
    }
    return 0;
}