class Solution {
public:
    string removeDuplicates(string s) {
        string res(s);
        int len = res.size();
        for(int i = 0; i < len - 1; i++) {
            while(res[i] == res[i + 1]) {
                res.erase(res.begin() + i, res.begin() + i + 2);
                len -= 2;
                while((i > 0) && (i < len) && res[i] == res[i - 1]) i--;
            }
        }
        return res;
    }
};