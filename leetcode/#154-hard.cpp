/**
 * 154. Find Minimum in Rotated Sorted Array II
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo != hi){
            int mid = lo + (hi-lo) / 2;
            if (nums[mid] > nums[mid+1]) return nums[mid+1];
            
            if (nums[mid] < nums[hi]) hi = mid;
            else if (nums[mid] > nums[hi]) lo = mid+1;
            else hi--;
        }
        return nums[hi];
    }
};