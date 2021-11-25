/**
 * 496. Next Greater Element I
 * https://leetcode.com/problems/next-greater-element-i/
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        vector<int> ans;
        
        for (auto n : nums2){
            while (!st.empty() and st.top() < n){
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        for (auto n : nums1){
            ans.push_back(m.count(n) ? m[n] : -1);
        }
        return ans;
    }
};