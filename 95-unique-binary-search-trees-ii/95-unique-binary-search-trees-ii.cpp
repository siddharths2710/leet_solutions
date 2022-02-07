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
    vector<TreeNode*> genTreeRec(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        TreeNode* root;
        vector<TreeNode*> left_subtree;
        vector<TreeNode*> right_subtree;
        for(int i = start; i <= end; i++) {
            left_subtree = genTreeRec(start, i - 1);
            right_subtree = genTreeRec(i + 1, end);
            for(auto& left: left_subtree) {
                for(auto& right: right_subtree) {
                    root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
            
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        //Time complexity: derive from unique bst part 1
        if(!n) return vector<TreeNode*>();
        return genTreeRec(1, n);
    }
};