class Solution {
private: 
    string revert_to_base(string s) {
        int l = s.size();
        string res = "";
        int diff;
        for(int i = 1; i < l; i++) {
            diff = s[i] - s[i - 1];
            if(diff < 0) diff += 26;
            res += ('a' + diff + ':');
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> grp_map;
        for(auto& str: strings) {
            grp_map[revert_to_base(str)].push_back(str);
        }
        for(auto& kv : grp_map) {
            vector<string> grp = kv.second;
            sort(grp.begin(), grp.end());
            groups.push_back(grp);
        }
        return groups;
    }
};