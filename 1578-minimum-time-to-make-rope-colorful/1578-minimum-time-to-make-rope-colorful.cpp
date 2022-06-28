class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int max_cost = neededTime[0], res = neededTime[0];
        for(int i = 1; i < neededTime.size(); i++) {
            if(colors[i] != colors[i - 1]) {
                res -= max_cost;
                max_cost = 0;
            }
            res += neededTime[i];
            max_cost = max(neededTime[i], max_cost);
        }
        return res -  max_cost;
    }
};