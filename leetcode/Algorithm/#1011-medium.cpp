/**
 * 1011. Capacity To Ship Packages Within D Days
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 0;

        // init
        int m = 0;
        for (int weight: weights){
            m = max(m, weight);
            h += weight;
        }
        l = m;

        int ans = h;
        while (l <= h){
            int mid = l + (h-l)/2;
            if (check(weights, days, mid)){
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int check(vector<int>& weights, int days, int capacity){
        int d = 1, ww = 0;

        for (int w : weights){
            if (ww + w > capacity) {
                ww = 0;
                d++;
            }
            ww += w;
        }
        if (d > days) return false;
        return true;
    }
};
