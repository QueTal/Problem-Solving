/*
 * https://leetcode.com/problems/power-of-three/
 * 326. Power of Three
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        
        while(n >= 3){
            if(n%3) return false;
            n /= 3;
        }
        return n == 1;
    }
};