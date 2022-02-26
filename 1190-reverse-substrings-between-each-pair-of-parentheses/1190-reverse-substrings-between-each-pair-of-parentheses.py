class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = [""]
        for c in s:
            if c == '(': stack.append(""); continue
            elif c == ')':
                cur_str = stack.pop()
                stack[-1] += cur_str[::-1]
            else:
                stack[-1] += c
        return stack.pop()