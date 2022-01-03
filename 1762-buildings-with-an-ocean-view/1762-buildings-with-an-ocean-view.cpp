class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int len = heights.size();
        ans.push_back(0);
        for(int i = 1; i < len; i++) {
            while(!ans.empty() && heights[i] >= heights[ans.back()])
                  ans.pop_back();
            ans.push_back(i);
        }
        return ans;
    }
};