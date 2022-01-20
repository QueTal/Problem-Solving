#include <iostream>

using namespace std;

int N;
int in[100001], post[100001], Index[100001];

void pre(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd or postStart > postEnd) return;
    int root = Index[post[postEnd]];
    cout << in[root] << " ";

    pre(inStart, root-1, postStart, postStart+root-inStart-1);
    pre(root+1, inEnd, postStart+root-inStart, postEnd-1);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) { cin >> in[i]; Index[in[i]] = i; }
    for (int i = 1; i <= N; i++) cin >> post[i];

    pre(1, N, 1, N);
    return 0;
}