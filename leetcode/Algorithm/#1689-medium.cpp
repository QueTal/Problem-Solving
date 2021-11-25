/*
 * 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
 * https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 */ 

class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        return n[n.size()-1] - '0';
    }
};