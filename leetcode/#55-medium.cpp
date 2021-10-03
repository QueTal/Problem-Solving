/**
 * 55. Jump Game
 * https://leetcode.com/problems/jump-game/
 */ 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIdx = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i]+i >= lastIdx) lastIdx = i;
        }
        return lastIdx == 0;
    }
};