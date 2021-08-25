/**
 * 633. Sum of Square Numbers
 * https://leetcode.com/problems/sum-of-square-numbers/
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        while (2*a*a <= c){
            long b = sqrt(c - a*a);
            if (b*b + a*a == c) return true;
            a++;
        }
        return false;
    }
};