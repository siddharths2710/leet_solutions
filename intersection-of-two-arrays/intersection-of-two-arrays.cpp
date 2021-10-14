class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> int_vec;
        set<int> int_set;
        
        set<int> nums1_set;
        for(auto& num: nums1) {
            nums1_set.insert(num);
        }
        
        for(auto& num: nums2) {
            if(int_set.find(num) == int_set.end() && nums1_set.find(num) != nums1_set.end()) {
                int_set.insert(num);
                int_vec.push_back(num);
            }
        }
        return int_vec;
    }
};