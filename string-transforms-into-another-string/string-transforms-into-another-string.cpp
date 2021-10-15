class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(!str1.compare(str2))
            return true;
        unordered_map<char, char> char_map;
        set<char> str2_set;
        int l1 = str1.size();
        bool res = true;
        for(int i = 0; res && i < l1; i++) {
             
            if(char_map.find(str1[i]) == char_map.end()) {
                char_map[str1[i]] = str2[i];
            }
            else if(char_map[str1[i]] != str2[i])
                res = false;
            str2_set.insert(str2[i]);
        }
        return res && str2_set.size() < 26;
    }
};