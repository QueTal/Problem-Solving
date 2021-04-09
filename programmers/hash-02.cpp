/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42577
 * level : 2 / 전화번호 목록                                    
 * ******************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++){
        int len = phone_book[i].size();
        if(phone_book[i] == phone_book[i+1].substr(0, len)) return false;
    }
    return true;
}