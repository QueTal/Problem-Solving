/**
 * 331. Verify Preorder Serialization of a Binary Tree
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/1427037/C%2B%2B-Simple-and-Short-Solution-O(n)-TC-O(1)-SC-Explained
 */

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> input;
        string temp = "";
        
        for(auto c : preorder){
            if (c == ',' and temp != "") {input.push_back(temp); temp = "";}
            else if (c == '#') input.push_back("#");
            else if ('0' <= c and c <= '9') temp += c;
        }
        if (temp != "") input.push_back(temp);
        
        int cnt = 1;
        for(auto c : input){
            cnt--;
            if (cnt < 0) return false;
            if (c != "#") cnt += 2;   
        }
        return cnt == 0;
    }
};