/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * 153. Find Minimum in Rotated Sorted Array
 */ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 or nums[0] < nums[nums.size()-1]) return nums[0];
        
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi){
            int mid = lo + (hi-lo) / 2;
            if (nums[mid] > nums[mid+1]) return nums[mid+1];
            
            if (nums[mid] > nums[hi]) lo = mid;
            else if (nums[mid] < nums[hi]) hi = mid;
        }
        return nums[hi];
    }
};