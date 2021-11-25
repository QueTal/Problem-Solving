/**
 * 922. Sort Array By Parity II
 * https://leetcode.com/problems/sort-array-by-parity-ii/
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        int odd = 1, even = 0;
        
        for(int num : nums){
            if (num % 2 == 1) {answer[odd] = num; odd += 2;}
            else {answer[even] = num; even += 2;}
        }
        return answer;
    }
};