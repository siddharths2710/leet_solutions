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
    unordered_map<int, int> inorder_idx_map;
    int preorder_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            Preorder => do(middle), left, right
            inorder => left, do(middle), right
            For inorder arr, elems at left of root are at left subtree, 
            elems to the right are in the right subtree
            Logic:
                1. Build map of inorder keys and idx value (they serve as bound while traversing preorder arr)
                2. In recursion, keep initializing idx at preorder at root, and increment preorder_idx
                3. root-> left = rec call bound by l, map.get(root) - 1
                4. root-> right = rec call bound by map.get(root) + 1, r
                5. return root
        */
        
        int len = inorder.size();
        preorder_idx = 0;
        for(int i = 0; i < len; ++i) {
            inorder_idx_map[inorder[i]] = i;
        }
        return preorder_arr_to_tree(preorder, 0, len - 1);
    }
    TreeNode* preorder_arr_to_tree(vector<int>& preorder, int l, int r) {
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_idx++]);
        root->left = preorder_arr_to_tree(preorder, l, inorder_idx_map[root->val] - 1);
        root->right = preorder_arr_to_tree(preorder, inorder_idx_map[root->val] + 1, r);
        return root;
    }
};