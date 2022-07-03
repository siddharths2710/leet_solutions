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
    int kthSmallest(TreeNode* root, int k) {
        //Inorder traversal finding kth smallest
        stack<TreeNode*> s;
        int res = -1;
        while(res == -1) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            if(!--k) {
                res = root->val;
                break;
            }
            root = root->right;
        }
        return res;
    }
};