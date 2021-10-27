class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> group_map;
        vector<vector<string>> groups;
        string sorted_str;
        
        for(auto& str: strs) {
            sorted_str = string(str);
            sort(sorted_str.begin(), sorted_str.end());
            group_map[sorted_str].push_back(str);
        }
        /*
            group_map :=
                    {
                        "aet": ["eat", "tea"],
                        "ant": [tan, nat]
                    }
        */
        
        for(auto& entry: group_map) {
            groups.push_back(entry.second);
        }
        
        return groups;
    }
};