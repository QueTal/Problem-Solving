/*
 * https://programmers.co.kr/learn/courses/30/lessons/42897
 * level : 4 / 도둑질
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int size = money.size(), withHead = money[0], withTail = money[size-1];
    int a, b, res;
     
    // include head
     a = b = res = 0;
    for(int i = 2; i < size-1; i++){
        res = max(a+money[i], b);
        a = b;
        b = res;
    }
    withHead += res;
    
    // include tail
    a = b = res = 0;
    for(int i = 1; i < size-2; i++){
        res = max(a+money[i], b);
        a = b;
        b = res;
    }
    withTail += res;
    return withHead > withTail ? withHead : withTail;
}