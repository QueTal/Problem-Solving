/**
 * 441. Arranging Coins
 * https://leetcode.com/problems/arranging-coins/
 */

class Solution {
public:
    int arrangeCoins(int n) {
        long lo = 1, hi = n;
        
        while (lo <= hi) {
            long mid = lo + (hi-lo)/2;
            
            long val = 0;
            if (mid % 2 == 0) val = mid / 2 * (mid+1);
            else val = (mid + 1) / 2 * mid;
            
            if (val == n) return mid;
            
            if (val < n) lo = mid+1;
            else if (val > n) hi = mid-1;
        }
        return lo-1;
    }
};