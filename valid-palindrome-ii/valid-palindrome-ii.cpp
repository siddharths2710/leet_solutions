class Solution {
private:
    bool validPalindromeRec(string& s, int l, int u, int tolerance) {
        if(l >= u) return true;
        else if(s[l] != s[u]) {
            if(tolerance)
                return validPalindromeRec(s, l + 1, u, false) || validPalindromeRec(s, l, u - 1, false);
            else
                return false;
        }
        return validPalindromeRec(s, l + 1, u - 1, tolerance);
    }
public:
    bool validPalindrome(string s) {
        return validPalindromeRec(s, 0, s.size() - 1, true);
    }
};