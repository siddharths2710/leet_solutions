class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        //sort words based on lengths
        sort(words.begin(), words.end(), [](string words1, string words2){
            return words1.size() < words2.size();
        });
        
        //Store each word and length of max chain
        map<string, int> chain_map;
        
        int res = 0;
        
        /*
        From shortest to longest word
        Form next word removing 1 char each time from word
        */
        int word_len = -1;
        string word_temp;
        for(auto& word: words) {
            chain_map[word] = 1;
            word_len = word.size();
            for(int i = 0; i < word_len; i++) {
                word_temp = string(word);
                word_temp.erase(word_temp.begin() + i);
                if((chain_map.find(word_temp) != chain_map.end()) && (chain_map[word_temp] + 1 > chain_map[word]))
                    chain_map[word] = chain_map[word_temp] + 1;
            }
            res = max(res, chain_map[word]);
        }
        return res;
    }
};