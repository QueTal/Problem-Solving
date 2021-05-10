/*
 * 583. Delete Operation for Two Strings
 * https://leetcode.com/problems/delete-operation-for-two-strings/
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int alen = word1.size(), blen = word2.size();
        vector<vector<int>> LCS(word1.size()+1, vector<int>(word2.size()+1, 0));

        for(int i = 0; i < alen; i++){
            for(int j = 0; j < blen; j++){
                if(word1[i] == word2[j]) LCS[i+1][j+1] = LCS[i][j] + 1;
                else LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
            }
        }
        
        return alen + blen - 2 * LCS[alen][blen];
    }
};