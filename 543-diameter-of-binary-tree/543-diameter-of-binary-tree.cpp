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
/*

         10
         / \
        6   11
       / \   \
      5   9  12
     /   /
    4   8
   /   /
  3   7


*/
class Solution {
private:
    int diameter;
    int longestPath(TreeNode* root) {
        if(!root) return 0;
        
        int long_left = longestPath(root->left);
        int long_right = longestPath(root->right);
        
        diameter = max(diameter, long_left + long_right);
        
        return 1 + max(long_left, long_right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
    
};