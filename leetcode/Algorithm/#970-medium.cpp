/* 
 * https://leetcode.com/problems/powerful-integers/
 * 970. Powerful Integers
 */

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> a, b, res;
        int i = 0;
        
        if( x == 1 ) a.push_back(1);
        else{    
            while(1){
                if(pow(x,i) <= bound){
                    a.push_back(pow(x,i));
                    i++;
                }
                else break;
            }
        }
        
        i = 0;
        if(y == 1) b.push_back(1);
        else{
            while(1){
                if(pow(y,i) <= bound){
                    b.push_back(pow(y,i));
                    i++;
                }
                else break;
            }   
        }
        
        set<int> s;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                if(a[i] + b[j] <= bound) s.insert(a[i]+b[j]);
            }
        }
        for(auto iter = s.begin(); iter != s.end(); iter++)
            res.push_back(*iter);
        return res;
    }
};