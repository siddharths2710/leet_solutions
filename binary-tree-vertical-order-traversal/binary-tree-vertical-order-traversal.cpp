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
private:
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> traverse_q;
        unordered_map<int, vector<int>> col_map;
        traverse_q.push(pair<int, TreeNode*>(0, root));
        int min_col = INT_MAX, max_col = INT_MIN;
        vector<vector<int>> res;
        if(!root) return res;
        TreeNode* cur_node;
        int cur_col;
        pair<int, TreeNode*> cur_pair;
        while(!traverse_q.empty()) {
            cur_pair = traverse_q.front();
            traverse_q.pop();
            cur_col = cur_pair.first;
            cur_node = cur_pair.second;
            if(col_map.find(cur_col) == col_map.end())
                col_map[cur_col] = vector<int>();
            col_map[cur_col].push_back(cur_node->val);
            if(cur_node->left)
                traverse_q.push(pair<int, TreeNode*>(cur_col - 1, cur_node->left));
            if(cur_node->right)
                traverse_q.push(pair<int, TreeNode*>(cur_col + 1, cur_node->right));
            min_col = min(min_col, cur_col);
            max_col = max(max_col, cur_col);
        }
        for(int c = min_col; c <= max_col; c++) {
            res.push_back(col_map[c]);
        }
        return res;
    }
};