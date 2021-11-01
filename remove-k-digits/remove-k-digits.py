class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # For sequence [D1, D2...Dn], If D1 > D2, we remove left neighbour D1 for the result
        # We use Stack for tracking purposes
        n_stack = []
        for digit in num:
            while k and n_stack and n_stack[-1] > digit:
                n_stack.pop() 
                k -= 1
            n_stack.append(digit)
            
        # Trunk remaining k digits at the end
        # if k == 0; return entire list
        final_stack = n_stack[:-k] if k else n_stack
            
        #Strip leading zeroes
        return "".join(final_stack).lstrip("0") or "0"