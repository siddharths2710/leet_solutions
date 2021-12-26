/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    vector<Node*> vec;
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        inorder_traverse(root);
        Node* head = nullptr;
        int len = vec.size();
        head = vec[0];
        head->left = vec[len - 1];
        if(len == 1) {
            head->right = vec[0];
            return head;
        }            
        head->right = vec[1];
        vec[len - 1]->left = vec[len - 2];
        vec[len - 1]->right = head;
        for(int i = 1; i < len - 1; i++) {
            vec[i]->left = vec[i - 1];
            vec[i]->right = vec[i + 1];
        }
        return head;
    }
    void inorder_traverse(Node * root) {
        if(root) {
            inorder_traverse(root->left);
            vec.push_back(root);
            inorder_traverse(root->right);   
        }
        return;
    }
};