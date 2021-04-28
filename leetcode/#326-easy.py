#
# https://leetcode.com/problems/power-of-three/
# 326. Power of Three
# 

class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        return 3**19 % n == 0
        