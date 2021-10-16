class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        if(!len) return res;
        else if(k >= len)  { 
            res.push_back(*max_element(nums.begin(), nums.end()));
            return res;
        }
        
        //deq which stores max at the front. Allways
        deque<int> slide_deq;
        for(int i = 0; i < len; i++) {
            
            //Remove indices not within the sliding window
            if(!slide_deq.empty() && slide_deq.front() == i - k) slide_deq.pop_front();
            
            //Remove indices from the last with elem lesser than nums[i] 
            while(!slide_deq.empty() && (nums[i] > nums[slide_deq.back()])) slide_deq.pop_back();
            slide_deq.push_back(i);
            
            if(i - k >= -1) res.push_back(nums[slide_deq.front()]);
        }
        
        return res;
    }
};