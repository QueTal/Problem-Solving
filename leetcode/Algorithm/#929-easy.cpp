/**
 * 929. Unique Email Addresses
 * https://leetcode.com/problems/unique-email-addresses/
 */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, set<string>> m;
        int cnt = 0;
        
        for(string email : emails){
            string local = "", domain = "";
            bool plus = false, dot = false;
            
            for (auto c : email){
                if (dot) domain += c;
                else {
                    if (c == '+') {plus = true; continue;}
                    if (c == '@') {dot = true; continue;}
                    if (plus) continue;
                    local = c != '.' ? local + c : local;
                }
            }
            cout << domain << " " << local << endl;
            m[domain].insert(local);
        }
        for(auto iter = m.begin(); iter != m.end(); iter++){
            // cout << iter << endl;
            cnt += iter->second.size();
        }
        return cnt;
    }
};