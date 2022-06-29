class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        int idx = 0, n = intervals.size();
        
        vector<vector<int>> res;
        while(idx < n && new_start > intervals[idx][0])
            res.push_back(intervals[idx++]);
        if(!res.size() || res[res.size() - 1][1] < new_start)
            res.push_back(newInterval);
        else
            res[res.size() - 1][1] = max(res[res.size() - 1][1], new_end);
        
        int start, end;
        while(idx < n) {
            start = intervals[idx][0];
            end = intervals[idx][1];
            if(res[res.size() - 1][1] < start)
                res.push_back(intervals[idx]);
            else
                res[res.size() - 1][1] = max(res[res.size() - 1][1], end);
            idx++;
        }
        return res;
    }
};