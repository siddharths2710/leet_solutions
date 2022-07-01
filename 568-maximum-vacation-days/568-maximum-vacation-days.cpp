class Solution {
private:
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int cur_city, int cur_week, vector<vector<int>>& memo) {
        if(cur_week == days[0].size()) return 0;
        if(memo[cur_city][cur_week] != INT_MIN)
            return memo[cur_city][cur_week];
        int max_vacation = 0;
        for(int i = 0; i < flights.size(); i++) {
            if(cur_city == i || flights[cur_city][i]) {
                int vacation = days[i][cur_week] + dfs(flights, days, i, cur_week + 1, memo);
                max_vacation = max(max_vacation, vacation);   
            }
        }
        memo[cur_city][cur_week] = max_vacation;
        return max_vacation;
    }
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        vector<vector<int>> memo(flights.size(), vector<int>(days[0].size(), INT_MIN));
        return dfs(flights, days, 0, 0, memo);
    }
    
};