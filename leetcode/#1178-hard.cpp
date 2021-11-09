/**
 * 1178. Number of Valid Words for Each Puzzle
 * https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
 */

class Solution {
public:
    int masking(string s){
        int mask = 0;
        for(auto c : s) mask |= 1 << (c-'a');
        return mask;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordCount;
        
        for(auto word: words){
            wordCount[masking(word)]++;
        }
        
        vector<int> result;
           
        for (auto puzzle : puzzles){
            int first = 1 << (puzzle[0] - 'a');
            int count = wordCount[first];
            
            int mask = masking(puzzle.substr(1));
            
            for (int submask = mask; submask; submask = (submask-1)&mask){
                count += wordCount[submask | first];
            }
            result.push_back(count);
        }
        
        return result;
    }
};