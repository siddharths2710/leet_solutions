class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        /* Two ideas for O(n)
            1. keep accruing sum
            2. sum of a given subarray from a to b --> sum[b] - sum[a] == target
                we track sum[a] (previous sums) in hash (map)
            3. We use map to store values of count of occurrence
        */
        map<int, int> prefix_map;
        prefix_map[0] = 0;
        int res = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(prefix_map.find(sum - target) != prefix_map.end()) {
                res = max(res, prefix_map[sum - target] + 1);
            }
            prefix_map[sum] = res;
        }
        return res;
    }
};