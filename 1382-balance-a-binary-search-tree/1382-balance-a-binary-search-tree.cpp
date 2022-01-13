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
    void inorder_traverse(TreeNode* node, vector<int>& list) {
        if(node) {
            inorder_traverse(node->left, list);
            list.push_back(node->val);
            inorder_traverse(node->right, list);
        }
    }
    TreeNode* balance_bst(vector<int>& list, int l, int h) {
        if(l > h ) return nullptr;
        else if(l == h) return new TreeNode(list[l]);
        int mid = (l + h) / 2;
        TreeNode* node = new TreeNode(list[mid]);
        node->left = balance_bst(list, l, mid - 1);
        node->right = balance_bst(list, mid + 1, h);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
         vector<int> inorder_list;
         inorder_traverse(root, inorder_list);
         return balance_bst(inorder_list, 0, inorder_list.size() - 1);
    }
};