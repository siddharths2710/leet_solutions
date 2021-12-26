class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second != b.second? a.second > b.second : a.first > b.first;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> ctr;
        vector<pair<int, int>> ctr_vec;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(ctr.find(nums[i]) != ctr.end())
                ctr[nums[i]] += 1;
            else
                ctr[nums[i]] = 1;
        }
        for(auto& it: ctr) {
            ctr_vec.push_back(it);
        }
        sort(ctr_vec.begin(), ctr_vec.end(), cmp);
        for(auto it = ctr_vec.begin(); (k--) && it != ctr_vec.end(); it++) {
            res.push_back(it->first);
        }
        return res;
    }
};