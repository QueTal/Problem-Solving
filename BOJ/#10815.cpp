#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500001];
int N, M;

bool bs(int target){
    int lo = 0, hi = N-1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (target == arr[mid]) return true;
        else if (target > arr[mid]) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main(void){
    cin.tie(0);//이 2줄 추가하면 맞음
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);

    cin >> M;
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        cout << bs(target) << " ";
    }

    return 0;
}