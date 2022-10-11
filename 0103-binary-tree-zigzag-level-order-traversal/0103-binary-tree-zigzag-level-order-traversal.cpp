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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> level_queue;
        if(!root) return res;
        level_queue.push(root);
        ssize_t size = 0;
        TreeNode* node;
        bool invert = false;
        while(!level_queue.empty()) {
            vector<int> level;
            size = level_queue.size();
            while(size--) {
                node = level_queue.front();
                level_queue.pop();
                if(node->left) level_queue.push(node->left);
                if(node->right) level_queue.push(node->right);
                level.push_back(node->val);
            }
            if(invert) reverse(level.begin(), level.end());
            res.push_back(level);
            invert = !invert;
        }
        return res;
    }
};