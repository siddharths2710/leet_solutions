class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int final_len = m + n;
        int cur_len = m;
        int ptr1 = 0, ptr2 = 0, idx;
        
        while((ptr2 < n) && (ptr1 < cur_len)) {
            if(nums1[ptr1] >= nums2[ptr2] ) {
                for(int i = cur_len; i > ptr1; i--) nums1[i] = nums1[i-1];
                nums1[ptr1] = nums2[ptr2++];
                cur_len++;
            }
            ptr1++;
        }
        
        while(ptr2 < n && ptr1 < final_len) {
            
            nums1[ptr1++] = nums2[ptr2++];
        }
    }
};