/**
 * 84. Largest Rectangle in Histogram
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int m = 0;
        
        for (int i = 0; i < heights.size(); i++){
            if (s.empty() or heights[i] >= heights[s.top()]) s.push(i);
            else {
                int h = heights[s.top()]; s.pop();
                m = max(m, h*(s.empty() ? i : i-1-s.top()));
                i--;
            }
        }
        return m;
    }
};