class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
       set<int> days_set(days.begin(), days.end());
       vector<int> dp(366);
       for(int i = 1; i < 366; i++) {
           dp[i] = dp[i - 1];
           if(days_set.find(i) != days_set.end()) {
               dp[i] = min({
                   dp[i - 1] + cost[0],
                   dp[max(0, i - 7)] + cost[1],
                   dp[max(0, i - 30)] + cost[2]
               });
           }
       }
        return dp[365];
    }
};