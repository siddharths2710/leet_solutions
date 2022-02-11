class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Optimized solution
        // use prefix and postfix product arrays
        //derive output from that
        //even simpler
        //Accrue prefix in output array
        //Maintain postfix variable from right to left
        //Accordingly multiply postfix with output location and update postfix product
        //return output
        int prefix = 1;
        int postfix = 1;
        int len = nums.size();
        vector<int> output(len, 0);
        for(int i = 0; i < len; i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = len - 1; i >= 0; i--) {
            output[i] *= postfix;
            postfix *= nums[i];
        }
        return output;
    }
};