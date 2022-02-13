class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> count_map;
        int len = s.size();
        for(int i = 0; i <= len -10; i++) {
            if(count_map.find(s.substr(i, 10)) == count_map.end()) count_map[s.substr(i, 10)] = 0;
            count_map[s.substr(i, 10)] += 1;
        }
        vector<string> res;
        for(auto& kv: count_map) {
            if(kv.second > 1)
                res.push_back(kv.first);
        }
        return res;
    }
};