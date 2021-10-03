class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int beg = 0;
        int end = len - 1;
        
        if( nums[beg] <= nums[end] )
            return nums[beg];
        int mid = (beg + end) >> 1;
        while(beg < end) {
            if(nums[beg] <= nums[end])
                return nums[beg];
            else if(beg < mid && nums[mid] > nums[end])
                beg = mid;
            else if(mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            else if(beg < mid && nums[(beg + mid) >> 1] > nums[mid] )
                beg = (beg + mid) >> 1;
            else beg++;
            mid = (beg + end) >> 1;
        }
        if(beg > end) return -1;
        return nums[beg];
    }
};