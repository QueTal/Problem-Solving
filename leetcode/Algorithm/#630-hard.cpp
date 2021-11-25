/*
 * 630. Course Schedule III
 * https://leetcode.com/problems/course-schedule-iii/
 */

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> heap;
        int now = 0;
        
        sort(courses.begin(), courses.end(), comp);

        for(int i = 0; i < courses.size(); i++){
            heap.push(courses[i][0]);
            now += courses[i][0];
            if (now > courses[i][1]){
                now -= heap.top(); 
                heap.pop();
            }
        }
        
        return heap.size();
    }
};

