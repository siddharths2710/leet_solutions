class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int new_digit = digits[len - 1] + 1;
        bool carry = (new_digit >= 10);
        vector<int> res;
        res.push_back(new_digit % 10);
        for(int i = len - 2; i >= 0; i--) {
            new_digit = ((int)carry + digits[i]);
            res.push_back(new_digit % 10);
            carry = (new_digit >= 10);
        }
        if(carry)
            res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};