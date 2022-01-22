class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*
            1. DP problem of decreasing order
            2. Borrow the sum in i+1, j+1 since we need to check against common subarray in num1 and num2
            3. We need the max. val present in the dp mem fn.
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        int max_val = 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));   
        for(int i = n1 - 1; i >= 0; i--) {
            for(int j = n2 - 1; j >= 0; j--) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    max_val = max(max_val, dp[i][j]);
                }
            }
        }
        return max_val;
    }
};