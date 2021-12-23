class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = nums.size();
        if(!l) return -1;
        else if(l == 1 || (nums[0] > nums[1])) return 0;
        else if(nums[l - 2] < nums[l - 1]) return l - 1;
        int index = -1;
        for(int i = 1; (index == -1) && (i < l - 1); i++) {
            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                index = i;
        }
        return index;
    }
};