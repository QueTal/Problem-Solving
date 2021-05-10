/*  
 * https://leetcode.com/problems/longest-common-subsequence/
 * 1143. Longest Common Subsequence
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int alen = text1.size(), blen = text2.size();
        vector<vector<int>> LCS(alen+1, vector<int>(blen+1, 0));
        
        for(int i = 0; i < alen; i++){
            for(int j = 0; j < blen; j++){
                if(text1[i] == text2[j]) LCS[i+1][j+1] = LCS[i][j] + 1;
                else LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
            }
        }
        return LCS[alen][blen];
    }
};