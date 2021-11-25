/**
 * 461. Hamming Distance
 * https://leetcode.com/problems/hamming-distance/
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        x = x^y;
        while(x){
            cnt += x&1;
            x >>= 1;
        }
        return cnt;
    }
};