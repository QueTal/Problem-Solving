#include <iostream>

using namespace std;

int N;

void star(int r, int c, int sz){
    if ((r / sz)%3 == 1 && (c / sz)%3 == 1) {
        cout << ' ';
    }
    else {
        if(sz / 3 == 0) cout <<'*';
        else star(r,c,sz/3);
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            star(i, j, N);
        }
        cout << "\n";
    }
    return 0;
}