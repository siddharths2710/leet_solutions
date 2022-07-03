class Solution {
public:
    void reverseWords(vector<char>& s) {
        /*
            Logic:
                1. reverse entire array in place
                2. Reverse every word until space in place
        */
        int l = s.size();
        int i, j;
        for(i = 0, j = l - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        i = 0; j = i + 1;
        do {
            while(j < l && s[j] != ' ') j++;
            if(j <= l) {
                for(int k = i, l = j - 1; k < l; k++, l--)
                    swap(s[k], s[l]);
                i = j + 1;
                j = i + 1;
            }
        } while(j < l);
        
    }
};