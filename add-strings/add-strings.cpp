class Solution {
public:
    string addStrings(string num1, string num2) {
        bool sign = true;
        if(!isdigit(num1[0])) {
            if(num1[0] == '-')
                sign = !sign;
            num1.erase(num1.begin());
        }
        if(!isdigit(num2[0])) {
            if(num2[0] == '-')
                sign = !sign;
            num2.erase(num2.begin());
        }
        int carry = 0;
        int l1 = num1.size();
        int l2 = num2.size();
        int min_len = (l1 < l2)? l1 : l2;
        int max_len = (l1 > l2)? l1 : l2;
        string min_str((num1.size() < num2.size())? num1 : num2);
        string max_str((num1.size() > num2.size())? num1 : num2);
        if(min_str == max_str) min_str = (min_str == num1)? num2: num1;
        string res("");
        int temp = 0;
        int diff = max_len - min_len;
        for(int i = max_len; i  > diff ; i--) {
            temp = (max_str[i - 1] - '0') + (min_str[i - diff - 1] - '0') + carry;
            res += to_string(temp % 10);
            carry = (temp / 10);
            
        }
        for(int i = diff; i > 0; i--) {
            temp = (max_str[i - 1] - '0') + carry;
            res += to_string(temp % 10);
            carry = (temp / 10);
        }
        if(carry)
            res += to_string(carry);
        if(!sign) res += "-";
        reverse(res.begin(), res.end());
        return res;
    }
};