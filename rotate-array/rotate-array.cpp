class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k >= len) k %= len;
        if(len < 2) return;
        for(int i = 0; i < len; i++) nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin() + (len - k));
        nums.erase(nums.begin() + len, nums.end());
    }
};