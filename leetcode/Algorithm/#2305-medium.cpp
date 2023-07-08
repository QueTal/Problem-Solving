/**
 * 2305. Fair Distribution of Cookies
 * https://leetcode.com/problems/fair-distribution-of-cookies/description/
 */

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        return solve(cookies, children, 0, INT_MAX);
    }
    
    int solve(vector<int>& v, vector<int>& children, int idx, int M) {
        if (idx == v.size()) {
            return *max_element(children.begin(), children.end());
        }
        for (int i = 0; i < children.size(); i++) {
            children[i] += v[idx];
            M = min(M, solve(v, children, idx+1, M));
            children[i] -= v[idx];
        }
        return M;
    }
};