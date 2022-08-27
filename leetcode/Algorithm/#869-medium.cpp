/**
 * 869. Reordered Power of 2
 * https://leetcode.com/problems/reordered-power-of-2/
 */

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        do{
            if (s[0] != '0' and isPowerOfTwo(stoi(s))) return true; 
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }
    
    bool isPowerOfTwo(int n){
        int cnt = 0;
        
        while (n){
            cnt += n&1;
            n >>= 1;
        }
            
        return cnt == 1;
    }
};