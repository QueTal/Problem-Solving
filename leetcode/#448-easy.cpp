/**
 * 448. Find All Numbers Disappeared in an Array
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        
        for(int i = 0; i < len; i++) {
            int m = abs(nums[i])-1; 
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};