/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* next_node;
        while(cur && cur->next) {
            next_node = cur;
            while((next_node->next) && next_node->next->val == cur->val)
                next_node = next_node->next;
            if((next_node) && next_node != cur) {
                cur->next = next_node->next;
            }
            cur = cur->next;
        }
        return head;
    }
};