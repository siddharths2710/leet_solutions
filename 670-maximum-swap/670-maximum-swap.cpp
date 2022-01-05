class Solution {
public:
    int maximumSwap(int num) {
        /*
            1. Do a right-to-left scan
                1.1 Find max_elem and max_idx in the comparison
                1.2 else find a second element lesser and to the left of max_elem for swap
                1.3 if lfet elem isn't found, return number itself
                1.4 else perform swap and return new number
        */
        if(!num) return 0;
        string s_num = to_string(num);
        int len = s_num.size();
        int max_digit = INT_MIN, max_idx = -1, left_idx = -1, right_idx = -1;
        for(int i = len - 1; i >= 0; i--) {
            if(s_num[i] > max_digit) {
                max_digit = s_num[i];
                max_idx = i;
                continue;
            }
            if(max_digit > s_num[i]) {
                left_idx = i;
                right_idx = max_idx;
            }
        }
        if(left_idx == -1) return num;
        swap(s_num[left_idx], s_num[right_idx]);
        return stoi(s_num);
    }
};