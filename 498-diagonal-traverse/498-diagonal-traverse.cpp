#define CHK_BOUNDS(i,j) ((((i >= 0) && (j >= 0)) && (i < m && j < n)))
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        /*
            Common index logic
        */
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dick(m + n - 1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dick[i + j].push_back(mat[i][j]);
            }
        }
        for(int i = 0; i < m + n - 1; i++) {
            if(!(i % 2))
                reverse(dick[i].begin(), dick[i].end());
            for(int j = 0; j < dick[i].size(); j++)
                res.push_back(dick[i][j]);
        }
        return res;
    }
};