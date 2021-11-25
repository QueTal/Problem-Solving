/**
 * 1189. Maximum Number of Balloons
 * https://leetcode.com/problems/maximum-number-of-balloons/
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        char c[5] = {'b','a','l','o','n'};
        int need[5] = {1, 1, 2, 2, 1};
        int m = INT_MAX;

        for (int i = 0; i < 5; i++){
            int val = count(text.begin(), text.end(), c[i]);
            m = min(m, val / need[i]);
        }
        return m;
    }
};