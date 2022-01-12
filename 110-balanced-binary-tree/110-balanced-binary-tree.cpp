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
    int getHeight(TreeNode* root) {
        //if(!root || !(root->left || root->right)) return 0;
        if(!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    int getBalanceFactor(TreeNode* node) {
        int left_height = getHeight(node->left);
        int right_height = getHeight(node->right);
        return left_height - right_height;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        return isBalanced(root->left) && isBalanced(root->right) && abs(getBalanceFactor(root)) <= 1;
    }
};