/**
 * 303. Range Sum Query - Immutable
 * https://leetcode.com/problems/range-sum-query-immutable/
 */

class NumArray {
private : 
    vector<int> memo;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums ){
            sum += num;
            memo.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0? memo[right] : memo[right] - memo[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */