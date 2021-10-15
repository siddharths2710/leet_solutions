class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.size();    
        stack<int> open_stack;
        set<int> reserve_idx;
        string res("");
        char c;
        for(int i = 0; i < len; i++) {
             c = s[i];
             if(c == '(') open_stack.push(i);
             else if(c == ')') {
                 if(!open_stack.empty()) {
                     reserve_idx.insert(i);
                     reserve_idx.insert(open_stack.top());
                     open_stack.pop();
                 }
             }
        }
        for(int i = 0; i < len; i++) {
            if(isalpha(s[i]) || (reserve_idx.find(i)) != reserve_idx.end())
                res += s[i];
        }
        return res;
    }
};