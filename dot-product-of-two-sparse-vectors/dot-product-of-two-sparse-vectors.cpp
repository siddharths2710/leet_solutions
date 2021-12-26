class SparseVector {    
public:
    map<int, int> vec1;
    int len;
    SparseVector(vector<int> &nums) {
        len = nums.size();
        for(int i = 0; i < len; i++ ) {
            if(nums[i])
                vec1[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(auto& vec_it : vec.vec1) {
            if(vec1.find(vec_it.first) != vec1.end())
                res += (vec_it.second * vec1[vec_it.first]);
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);