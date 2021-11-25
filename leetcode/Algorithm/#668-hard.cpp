/**
 * 668. Kth Smallest Number in Multiplication Table
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
 */

class Solution {
public:
    bool binarySearch(int x, int m, int n, int k){
        int cnt = 0;
        for (int i = 1; i <= m; i++){
            cnt += min(x/i, n);
        } 
        return cnt >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        
        while (lo < hi){
            int mid = lo + (hi-lo)/2;
            if (!binarySearch(mid, m, n, k)) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};