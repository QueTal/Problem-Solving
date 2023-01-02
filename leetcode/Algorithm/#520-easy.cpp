/**
 * 520. Detect Capital
 * https://leetcode.com/problems/detect-capital/description/
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        for (auto w : word){
            if (w <= 'Z') c++;
        }
        if (c == 0 or word.size() == c) return true;
        return c == 1 and word[0] <= 'Z';
    }
};