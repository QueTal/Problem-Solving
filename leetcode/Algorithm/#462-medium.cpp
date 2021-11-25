/*
 * 462. Minimum Moves to Equal Array Elements II
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0, avg = 0;
        
        sort(nums.begin(), nums.end());
        avg = nums[nums.size()/2];
        
        for(auto num : nums) sum += abs(num - avg);
        return sum;
    }
};