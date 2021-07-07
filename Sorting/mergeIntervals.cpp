#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 1) return intervals;
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> sol;
    
    int start = intervals[0][0], end=intervals[0][1];
    for(int i=1; i<intervals.size(); i++){
        if(end < intervals[i][0]){
            sol.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        } else {
            end = max(intervals[i][1], end);
        }
    }
    sol.push_back({start, end});
    return sol;
}