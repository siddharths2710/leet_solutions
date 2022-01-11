class Solution {
private:
    bool dfs_check_diagonal(vector<vector<int>>& matrix, int m, int n, int i, int j) {
        //cout<<i<<":"<<j<<endl;
        if(i == m || j == n) return true;
        else if((i < m && j < n) && (matrix[i - 1][j - 1] != matrix[i][j])) return false;
        return dfs_check_diagonal(matrix, m, n, i + 1, j + 1);
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool toeplitz_check_so_far = true;
        for(int i = 1; toeplitz_check_so_far && i < m; i++) {
            for(int j = 1; toeplitz_check_so_far && j < n; j++)
                toeplitz_check_so_far &= dfs_check_diagonal(matrix, m, n, i, j);
        }
        
        return toeplitz_check_so_far;
    }
};