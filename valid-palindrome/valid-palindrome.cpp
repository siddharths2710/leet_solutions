class Solution {
private:
    int is_char_ignore(char c) {
        return ispunct(c) || isdigit(c) || (c == ' ');
    }
public:
    bool isPalindrome(string s) {
        int l = s.size();
        bool match = true;
        for(int i = 0, j = l - 1; match && (j >= i); i++, j--) {
            while((i < l) && !isalnum(s[i])) i++;
            while((j >= 0) && !isalnum(s[j])) j--;
            if(i > j) break;
            if(isalpha(s[i]) && isalpha(s[i] + 32)) s[i] += 32;
            if(isalpha(s[j]) && isalpha(s[j] + 32)) s[j] += 32;
            if(s[i] != s[j]) match = false;
        }
        return match;
    }
};