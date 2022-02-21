class Solution {
private:
    map<char, char> rotate_equivalent;
    void initialize_rotate() {
        rotate_equivalent = {{'6', '9'}, {'9', '6'}, {'8', '8'}, {'0', '0'}, {'1', '1'}};
    }
public:
    bool isStrobogrammatic(string num) {
        initialize_rotate();
        int len = num.size();
        bool found = true;
        for(int i = 0,j = len - 1;found && i <= j; i++, j--) {
            if(rotate_equivalent.find(num[i]) == rotate_equivalent.end() 
                || rotate_equivalent[num[i]] != num[j]) {
                found = false;
            }
                
        }
        return found;
    }
};