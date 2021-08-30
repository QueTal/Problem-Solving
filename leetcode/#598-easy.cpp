/**
 * 598. Range Addition II
 * https://leetcode.com/problems/range-addition-ii/
 */ 
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return n*m;
    }
};