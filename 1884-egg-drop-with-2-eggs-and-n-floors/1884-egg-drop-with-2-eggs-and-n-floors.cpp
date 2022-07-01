class Solution {
public:
    int twoEggDrop(int n) {
        /*
        int eggs = 2;
        vector<vector<int>> dp(n + 1, vector<int>(eggs + 1, 0));
        return drop_recurse(n, eggs, dp);
        */
        return ceil((sqrt(8*n + 1) - 1) / 2);
    }
    int drop_recurse(int floors, int eggs, vector<vector<int>>& dp) {
        if(eggs == 1 || floors <= 1) return floors;
        if(dp[floors][eggs] > 0) return dp[floors][eggs];
        int min_eggs = INT_MAX;
        for(int f = 1; f <= floors; f++) {
            min_eggs = min(min_eggs, 1 + max(drop_recurse(f - 1, eggs - 1, dp), drop_recurse(floors - f, eggs, dp)));
        }
        return min_eggs;
    }
};