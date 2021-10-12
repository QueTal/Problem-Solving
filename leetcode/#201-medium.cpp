/**
 * 201. Bitwise AND of Numbers Range
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) return 0;
        while (left < right){
            right &= right -1;
        }
        return right;
    }
};