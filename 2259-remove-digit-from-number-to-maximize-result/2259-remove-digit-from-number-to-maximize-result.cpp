class Solution {
public:
    string removeDigit(string number, char digit) {
        bool removed = false;
        int i;
        for(i = 0; !removed && number[i] != '\0'; i++) {
            if(number[i + 1] != '\0' && number[i] == digit && number[i] < number[i+1]) {
                number.erase(number.begin() + i);
                removed = true;
            }
        }
        for(int j = i - 1; !removed && j >= 0; j--) {
            if(number[j] == digit) {
                number.erase(number.begin() + j);
                removed = true;
            }
        }
        return number;
    }
};