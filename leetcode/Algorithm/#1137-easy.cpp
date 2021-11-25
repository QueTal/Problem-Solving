/**
 * 1137. N-th Tribonacci Number
 * https://leetcode.com/problems/n-th-tribonacci-number/
 */ 

class Solution {
private: 
    int memo[38] = {0};
public:
    int tribonacci(int n) {
        if (memo[n] > 0) return memo[n];
        if (n == 0) {memo[0] = 0; return 0;}
        else if (n == 1) {memo[1] = 1; return 1;}
        else if (n == 2) {memo[2] = 1; return 1;}
        memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return memo[n];
    }
};