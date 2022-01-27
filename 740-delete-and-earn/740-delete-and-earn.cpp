class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    int n = 10000;
    
    vector<int> freq(n + 1, 0);
    vector<int> dp(n + 1, 0);
    
    for(auto num: nums){
        freq[num]++;
    }
    
    dp[0] = 0;
    dp[1] = freq[1];
    /* House robber concept:
       dp[num] = max(case you include num, case you exclude num)
            =   max(dp[num - 2] + num * freq, dp[num - 1])
    */
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-2] + i * freq[i], dp[i-1]);
    }
    
    return dp[n];
}

};