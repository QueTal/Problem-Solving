/*
 * 로또의 최고 순위와 최저 순위
 * https://programmers.co.kr/learn/courses/30/lessons/77484
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int bs(vector<int>& win, int target, int start, int end){
    while(start < end){
        int mid = start + (end-start)/2;
        if(win[mid] == target) return mid;
        else if(win[mid] > target) end = mid;
        else start = mid + 1;
    }
    return -1;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int find = 0, zero = 0;
    int start = 0, end = lottos.size();
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(auto lotto : lottos){
        if(lotto == 0) { zero++; continue; }
        else {
            int temp = bs(win_nums, lotto, start, end);
            if(temp != -1) find++;
            start = temp == -1? start : temp;
        }
    }
    
    if(find+zero > 1) answer.emplace_back(7-(find+zero));
    else answer.emplace_back(6);
    if(find > 1) answer.emplace_back(7-find);
    else answer.emplace_back(6);

    return answer;
}