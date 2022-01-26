class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> row_vec(i + 1, 0);
            row_vec[0] = 1;
            row_vec[i] = 1;
            for(int j = 1; j < i; j++) {
                row_vec[j] = res.back()[j - 1] + res.back()[j];
            }
            res.push_back(row_vec);
        }
        return res;
    }
};