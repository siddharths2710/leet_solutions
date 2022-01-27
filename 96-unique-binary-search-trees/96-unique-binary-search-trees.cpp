class Solution {
public:
    int numTrees(int n) {
        /*
            Basic Idea: 
                    Assume n = 7
                    Consider root (i) = 3, 1 <= i <= n
                         3
                       /  \
                   [1, 2] [4,5,6,7]
                 No. of unique bsts with root as 3
                    = (no of bsts of [1,2]) * (no of bsts [4,5,6,7])
                    = (no of bsts of [1,2]) * (no of bsts [1,2,3,4])
                Total bsts of n = 7
                 = \sigma_1^n_j (no of bsts till j) * ((no of bsts of n - j)
        */
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=n; i++) {
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};