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
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        stack<TreeNode*>* stack_ptr = &s1;
        vector<vector<int>> res;
        bool flip = false;
        TreeNode* temp_node;
        vector<int> temp_vec;
        if(!root)
            return res;
        s1.push(root);    
        while(!(s1.empty() && s2.empty())) {
            if(stack_ptr->empty()) {
                res.push_back(temp_vec);
                temp_vec.clear();
                flip = !flip;
                stack_ptr = (s1.empty())? &s2: &s1;
            }
            temp_node = (TreeNode*)stack_ptr->top();
            stack_ptr->pop();
            temp_vec.push_back(temp_node->val);
            if(!flip) {
                if(temp_node->left)
                    s2.push(temp_node->left);
                if(temp_node->right)
                    s2.push(temp_node->right);
            } else {
                if(temp_node->right)
                    s1.push(temp_node->right);
                if(temp_node->left)
                    s1.push(temp_node->left);
            }
        }
        if(!temp_vec.empty())
            res.push_back(temp_vec);
        return res;
    }
};