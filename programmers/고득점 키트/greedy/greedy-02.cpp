/*
 * https://programmers.co.kr/learn/courses/30/lessons/42860 
 * level : 2 / 조이스틱
 */

#include <algorithm>

using namespace std;

int val[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0, len = name.length(), left_right = len - 1;
    
    for (auto ch : name)
        answer += val[ch - 'A'];
    
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}