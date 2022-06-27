class Solution {
public:
    int numSteps(string s) {
        if(!s.compare("1")) return 0;
        int steps = 0, carry = 0;
        for(int i = s.length() - 1; i > 0; i--) {
            steps++; //we'll reach the even case regardless
            
            //Odd case
            if(s[i] - '0' + carry == 1) {
                carry = 1;
                steps++;
            }
        }
        return steps + carry;
    }
};

//11
/*
    
    

*/