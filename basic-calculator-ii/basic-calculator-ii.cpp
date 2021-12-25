class Solution {
private:
    int read_and_push(stack<int>& st, string& str, int idx, int len, int sign) {
        if(!isdigit(str[idx]))
            return -1;
        int res = 0;
        while((idx < len) && isdigit(str[idx])) {
            res = (res * 10) + (str[idx] - '0');
            idx++;
        }
        st.push(res * sign);
        return idx - 1;
    }
public:
    int calculate(string s) {
        stack<int> num_stack;
        int len = s.size();
        int op1, op2;
        for(int i = 0; i < len; i++) {
            switch(s[i]) {
                case ' ': continue;
                case '+':   while((i < len) && s[i + 1] == ' ') i++;
                            if(isdigit(s[i + 1]))
                                i = read_and_push(num_stack, s, i + 1, len, +1); break;
                case '-': while((i < len) && s[i + 1] == ' ') i++;
                            if(isdigit(s[i + 1]))
                                i = read_and_push(num_stack, s, i + 1, len, -1); break;
                case '*': if((i < len) && s[i + 1] == '-') 
                            i = read_and_push(num_stack, s, i + 2, len, -1);
                          else if((i < len) && s[i + 1] == '+')
                              i = read_and_push(num_stack, s, i + 2, len, +1);
                          else
                              i = read_and_push(num_stack, s, i + 1, len, +1);
                          op1 = num_stack.top(); num_stack.pop();
                          op2 = num_stack.top(); num_stack.pop();
                          num_stack.push(op1 * op2);
                          break;
                case '/':   if(i < len - 1) {
                                switch(s[i + 1]) {
                                    case '-': i = read_and_push(num_stack, s, i + 2, len, -1); break;
                                    case '+': i = read_and_push(num_stack, s, i + 2, len, +1); break;
                                    case ' ': while(s[i + 1] == ' ') i++;
                                    default: if(isdigit(s[i + 1]))
                                        i = read_and_push(num_stack, s, i + 1, len, +1); break;
                                }
                                op1 = num_stack.top(); num_stack.pop();
                                op2 = num_stack.top(); num_stack.pop();
                                num_stack.push(op2 / op1);
                            } break;
                          
                default:  i = read_and_push(num_stack, s, i, len, +1);
            }
        }
        int res = 0;
        while(!num_stack.empty()) {
            res += num_stack.top();
            num_stack.pop();
        }
        return res;
    }
};