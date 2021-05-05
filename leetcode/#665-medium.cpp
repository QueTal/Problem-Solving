/*
 * 665. Non-decreasing Array
 * https://leetcode.com/problems/non-decreasing-array/
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool checked = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                if(checked) return false;
                checked = true;
                (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
                // 2 5 3
            }    
        }
        return true;
    }
};