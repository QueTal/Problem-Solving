#include <iostream>
#include <unordered_map>

using namespace std;

int N;

void preorder(unordered_map <char, char>& left, unordered_map <char, char>& right, char node){
    if (node == '.') return;
    cout << node;
    preorder(left, right, left[node]);
    preorder(left, right, right[node]);
}

void inorder(unordered_map <char, char>& left, unordered_map <char, char>& right, char node){
    if (node == '.') return;
    inorder(left, right, left[node]);
    cout << node;
    inorder(left, right, right[node]);
}

void postorder(unordered_map <char, char>& left, unordered_map <char, char>& right, char node){
    if (node == '.') return;
    postorder(left, right, left[node]);
    postorder(left, right, right[node]);
    cout << node;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    unordered_map <char, char> left, right;
    char p, l, r;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> p >> l >> r;
        left[p] = l; right[p] = r;
    }

    preorder(left, right, 'A'); cout << endl;
    inorder(left, right, 'A'); cout << endl;
    postorder(left, right, 'A');

    return 0;
}