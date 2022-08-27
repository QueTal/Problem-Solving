"""
869. Reordered Power of 2
https://leetcode.com/problems/reordered-power-of-2/
"""

class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return any(num[0] != '0' and bin(int("".join(num))).count('1') == 1 for num in itertools.permutations(str(n)))
        