/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            > O(N) time, O(N) space, store visited nodes of A on a set, and check against that while traversing B
            > O(M + N) time, O(1) space ?
            
        */
        if(!headA || !headB) return nullptr;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while(cur1 != cur2) {
            if(!cur1) cur1 = headB;
            else cur1 = cur1->next;
            if(!cur2) cur2 = headA;
            else cur2 = cur2->next;
        }
        return cur1;
    }
};