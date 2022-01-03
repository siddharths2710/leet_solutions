class Solution {
private:
    vector<int> cum_vec;
public:
    Solution(vector<int>& w) {
        //Cumulative sum accrual
        partial_sum(w.begin(), w.end(), back_inserter(cum_vec));
    }
    
    int pickIndex() {
        //rand() generates any number between 0 and RAND_MAX
        //rand() in c++ --> rand() % u + l for generating within u and l
        //upper bound --> idx of first element greater than rand() freq obtained
        int max_freq = cum_vec.back();
        int rand_freq = rand() % max_freq;
        return upper_bound(cum_vec.begin(), cum_vec.end(), rand_freq) - cum_vec.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */