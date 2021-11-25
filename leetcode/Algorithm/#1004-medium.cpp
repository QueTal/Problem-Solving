/*
 * 1004. Max Consecutive Ones III
 * https://leetcode.com/problems/max-consecutive-ones-iii/
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, i = 0;
        int cur = 0, max = 0;
        bool endChanged = true;
        
        while (end < nums.size()){
            if (endChanged and nums[end] == 0) cur++;
                
            if (cur <= k){
                max = max > (end - start + 1) ? max : (end - start + 1);
                end++;
                endChanged = true;
            }
            else {
                if (nums[start] == 0) cur--;
                start++;
                endChanged = false;
            }
        }
        return max;
    }
};