/**
 * 137. Single Number II
 * https://leetcode.com/problems/single-number-ii/description/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;

        for (auto num: nums) {
            one ^= (num & ~two);
            two ^= (num & ~one);
        }
        return one;
    }
};