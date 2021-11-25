/**
 * 485. Max Consecutive Ones
 * https://leetcode.com/problems/max-consecutive-ones/
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0;
        int hi, lo;
        hi = lo = 0;
        
        while (hi < nums.size()){
            if (nums[lo] == 1 and nums[hi] == 1) {
                answer = max(answer, hi - lo + 1);
                hi++;   
                continue;
            }
            
            if (nums[lo] != 1) lo++;
            if (nums[hi] != 1) hi++, lo = hi;
        }
        return answer;
    }
};