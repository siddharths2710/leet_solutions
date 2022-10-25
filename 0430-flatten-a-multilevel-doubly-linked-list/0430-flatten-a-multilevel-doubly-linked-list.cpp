/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* cur = head;
        while(cur) {
            if(cur->child) {
                Node* child = flatten(cur->child);
                Node* cur_next = cur->next;
                Node* child_tail = child;
                while(child_tail->next)
                    child_tail = child_tail->next;
                cur->next = child;
                child->prev = cur;
                child_tail->next = cur_next;
                cur->child = nullptr;
                if(cur_next) cur_next->prev = child_tail;
                cur = cur_next;
            } else
                cur = cur->next;
        }
        return head;
    }
};