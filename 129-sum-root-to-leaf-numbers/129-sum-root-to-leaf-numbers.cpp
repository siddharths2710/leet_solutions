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
    void sumRtoL(TreeNode* node, int cur, vector<int>& list) { 
        cur = cur * 10 + node->val;
        int no_child = 0;
        if(node->left) {
            no_child++;
            sumRtoL(node->left, cur, list); 
        }
        if(node->right) {
            no_child++;
            sumRtoL(node->right, cur, list);
        }
        if(!no_child)
            list.push_back(cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int> list;
        sumRtoL(root, 0, list);
        return accumulate(list.begin(), list.end(), 0);
    }
};