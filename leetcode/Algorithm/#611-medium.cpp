/*
 * 611. Valid Triangle Number
 * https://leetcode.com/problems/valid-triangle-number/
 */ 

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0, k; i < nums.size() - 2; i++){
            k = i + 2;
            for(int j = i + 1; j < nums.size() - 1 && nums[i] != 0 ; j++){
                while(k < nums.size() && nums[i] + nums[j] > nums[k]) k++;
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
};
