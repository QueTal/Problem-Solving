/*
 * 1338. Reduce Array Size to The Half
 * https://leetcode.com/problems/reduce-array-size-to-the-half/
 */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> freq(100004,0);
        for(int i=0;i<arr.size();i++){
                freq[arr[i]]++;
        }
        sort(freq.begin(),freq.end(),greater<>());
        int n = arr.size();
        n = n/2;
        int count = 0;
        int sum = 0;
        for(int i=0;i<freq.size();i++){
                sum += freq[i];
                count++;
                if(sum>=n)break;
        }
        return count;
    }
};