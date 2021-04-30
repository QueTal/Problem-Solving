#
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
# 34. Find First and Last Position of Element in Sorted Array
# 

class Solution(object):
    def searchRange(self, nums, target):
        
        def bs(self, nums, target):
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid
            return lo
        
        res = [-1, -1]
        res[0] = bs(self, nums, target)
        if res[0] >= len(nums) or nums[res[0]] != target:
            return [-1, -1]
        res[1] = bs(self, nums, target+1) - 1
        return res