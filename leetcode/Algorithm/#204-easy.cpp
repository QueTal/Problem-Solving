/*
 * 204. Count Primes
 * https://leetcode.com/problems/count-primes/ 
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> visited(n, false);
        int count = 1;
        
        if(n <= 2) return 0;
        for(int i = 3; i < n; i+=2){
            //even number is not prime
            if(!visited[i]){
                count++;
                if(i <= sqrt(n)){
                    for(int j = i*i; j < n; j += i)
                        visited[j] = true;
                }
            }        
        }
        return count;
    }
};