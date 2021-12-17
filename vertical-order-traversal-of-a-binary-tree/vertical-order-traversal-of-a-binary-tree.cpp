/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /*
        Create a map of the following order:
        {
            "col": [row1 < row2 = row3 (>val)]
        }
        Check on LeetHub
        */
        unordered_map<int, unordered_map<int, vector<int>>> dict;
        vector<vector<int>> res;
        if(!root) return res;
        dict[0][0].push_back(root->val);
        if(root->left) {
            dict[-1][1].push_back(root->left->val);
            dfs_explore(root->left, -1, 1, dict);
        } if(root->right) {
            dict[1][1].push_back(root->right->val);
            dfs_explore(root->right, 1, 1, dict);
        }
        vector<int> dict_keys;
        vector<int> dict_row_keys;
        vector<int> key_vals;
        for(auto it = dict.begin(); it != dict.end(); it++) {
            dict_keys.push_back(it->first);
        }
        sort(dict_keys.begin(), dict_keys.end());
        for(auto& key: dict_keys) {
            //sort(dict[key].begin(), dict[key].end());
            dict_row_keys.clear();
            for(auto it = dict[key].begin(); it != dict[key].end(); it++) {
                dict_row_keys.push_back(it->first);
            }
            sort(dict_row_keys.begin(), dict_row_keys.end());
            key_vals.clear();
            for(auto& row_key : dict_row_keys) {
                sort(dict[key][row_key].begin(), dict[key][row_key].end());
                for(auto& elem: dict[key][row_key]) {
                    key_vals.push_back(elem);
                }
            }
            res.push_back(key_vals);
        }
        return res;
    } 
private:
    void dfs_explore(TreeNode* root, int col, int row, unordered_map<int, unordered_map<int, vector<int>>>& dict) {
        if(root->left) {
            dict[col - 1][row + 1].push_back(root->left->val);
            dfs_explore(root->left, col - 1, row + 1, dict);
        }
        if(root->right) {
            dict[col + 1][row + 1].push_back(root->right->val);
            dfs_explore(root->right, col + 1, row + 1, dict);
        }
    }
};