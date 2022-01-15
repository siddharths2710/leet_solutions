class Solution {
private:
    void insertDots(string& s, string cur, vector<string>& res, int l, int u, int dots) {
        string temp;
        for(int i = 1; i < 4; i++) {
            if(l + i > u) break;
            temp = s.substr(l, i);
            if((temp[0] == '0' && i == 1) || (temp[0] != '0' && (stoi(temp) < 256))) {
               if(!dots && (l + i == u)) {
                   res.push_back(cur + temp);
               }
               else
                 insertDots(s, cur + temp + ".", res, l + i, u, dots - 1); 
            }
               
        }   
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur("");
        insertDots(s, cur, res, 0, s.size() , 3);
        return res;
    }
};