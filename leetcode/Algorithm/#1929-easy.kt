class Solution {
    fun getConcatenation(nums: IntArray) = IntArray(nums.size * 2) { nums[it % nums.size] }
}