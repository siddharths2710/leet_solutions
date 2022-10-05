class Solution {
private:
    void backtrack(vector<string>& res, vector<char>& br, int open, int close, int max) {
        if(br.size() == max << 1) {
            string pattern = "";
            for(auto& b: br) pattern += b;
            res.push_back(pattern);
        }
        if(open < max) {
            br.push_back('(');
            backtrack(res, br, open + 1, close, max);
            br.pop_back();
        }
        if(close < open) {
            br.push_back(')');
            backtrack(res, br, open, close + 1, max);
            br.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<char> brackets;
        backtrack(ans, brackets, 0, 0, n);
        return ans;
    }
};