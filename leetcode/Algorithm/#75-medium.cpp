/**
 * 75. Sort Colors
 * https://leetcode.com/problems/sort-colors/
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r =  nums.size()-1, i = 0;
        
        while (i <= r){
            if (nums[i] == 0) {
                swap(nums[l++], nums[i++]);
            }
            else if (nums[i] == 2){
                swap(nums[r--], nums[i]);
            }
            else i++;
        }
    }
};