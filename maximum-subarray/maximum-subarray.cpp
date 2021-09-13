class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0];
        int global_sum = nums[0];
        for(int i = 1; i< nums.size(); i++) {
            cur_sum = max(cur_sum + nums[i], nums[i] );
            global_sum = max(global_sum, cur_sum);
        }
        return global_sum;
    }
};