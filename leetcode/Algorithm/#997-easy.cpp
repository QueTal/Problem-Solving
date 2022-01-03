/**
 * 997. Find the Town Judge
 * https://leetcode.com/problems/find-the-town-judge/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int check[1001] = {}, index = 0, val = 0;
        bool isTrust[1001] = {};
        
        if (n == 0) return -1;
        if (n == 1 and trust.size() != 0) return -1;
        else if (n == 1 and trust.size() == 0) return 1;
        
        for (auto t : trust){
            isTrust[t[0]] = true;
            check[t[1]]++;
            if (check[t[1]] > val) {
                index = t[1];
                val = check[t[1]];
            }
        } 
        if (check[index] == n-1 and !isTrust[index]) return index;
        else return -1;
    }
};