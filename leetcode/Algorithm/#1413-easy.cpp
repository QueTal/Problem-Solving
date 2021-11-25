/**
 * 1413. Minimum Value to Get Positive Step by Step Sum
 * https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 */

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) nums[i] += nums[i-1]; 
        int m = *min_element(nums.begin(), nums.end());
        return m >= 1 ? 1 : -m + 1;
    }
};