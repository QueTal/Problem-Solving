/**
 * 476. Number Complement
 * https://leetcode.com/problems/number-complement/
 */

class Solution {
public:
    int findComplement(int num) {
        int exp = 0, answer = 0;
        while (num){
            answer += num%2 == 1 ? 0 : pow(2, exp); 
            num /= 2;
            exp++;
        }
        return answer;
    }
};