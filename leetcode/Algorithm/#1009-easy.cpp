/**
 * 1009. Complement of Base 10 Integer
 * https://leetcode.com/problems/complement-of-base-10-integer/
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        string s = "";
        
        if (n == 0) return 1;
        
        while (n){
            s += (n%2 == 1) ? '0' : '1';
            n /= 2;
        }
        
        int res = 0, power = 0;
        while (s != ""){
            res += pow(2, power) * (s[0]-'0');
            power++;
            s = s.substr(1);
        }
        return res;
    }
};