class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //Create an ordered map to store precedence
        int order_map[26];
        for(int i = 0; i < 26; i++) {
            order_map[order[i] - 'a'] = i;
        }
        int warr_size = words.size();
        string word1, word2;
        bool check_sorted = true, check_same = true;
        for(int i = 0; check_sorted && i < warr_size - 1; i++) {
            word1 = words[i];
            word2 = words[i + 1];
            check_same = true;
            for(int j = 0; j < word1.size(); j++) {
                //If all chars till 'j - 1' are equal, and jth char exists in word1 and not word2
                if(check_same && j >= word2.size()) {
                    check_sorted = false;
                    break;
                }
                if(word1[j] != word2[j]) {
                    if(order_map[word1[j] - 'a'] > order_map[word2[j] - 'a'])
                        check_sorted = false;
                    check_same = false;
                    break;
                }
            }
        }
        return check_sorted;
    }
};