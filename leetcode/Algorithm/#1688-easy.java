/**
https://leetcode.com/problems/count-of-matches-in-tournament/description/?envType=daily-question&envId=2023-12-05
 */


class Solution {
    public int numberOfMatches(int n) {
        int cnt = 0;

        while (n > 1) {
            cnt += n/2;
            if (n % 2 == 0) n /= 2;
            else n = (n+1)/2;
        }
        
        return cnt;
    }
}