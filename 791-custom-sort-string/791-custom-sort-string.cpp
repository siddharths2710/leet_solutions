class Solution {
public:
    string customSortString(string order, string s) {
        /*
            1. Get counter of ltrs in s
            2. Add elems to res based on count values of letters in 'order'
            3. Add remaining elements not accounted for by 'order' into res
        */
        int ord_len = order.size();
        int str_len = s.size();
        if(!(ord_len && str_len)) return s;
        map<char, int> ctr;
        for(char& c : s) {
            if(ctr.find(c) == ctr.end()) ctr[c] = 0;
            ctr[c] += 1;
        }
        string res;
        for(char& o : order) {
            if(ctr.find(o) != ctr.end()) {
                while(ctr[o]--) res += o;
                ctr.erase(o);
            }
        }
        char ltr;
        int count;
        for(auto& elem : ctr) {
            ltr = elem.first;
            count = elem.second;
            while(count--) res += ltr;
        }
        return res;
    }
};