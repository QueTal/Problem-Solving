/**
 * 1629. Slowest Key
 * https://leetcode.com/problems/slowest-key/
 */

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char maxKey = keysPressed[0];
        int maxTime = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (t > maxTime || t == maxTime && maxKey < keysPressed[i]) {
                maxKey = keysPressed[i];
                maxTime = t;
            }
        }
        return maxKey;
    }
};