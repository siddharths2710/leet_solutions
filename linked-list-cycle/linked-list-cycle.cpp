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
    bool hasCycle(ListNode *head) {
        if(!head || !(head->next))
            return false;
        set<ListNode*> visited;
        ListNode* cur = head;
        bool check_cycle = false;
        do {
            if(visited.find(cur) != visited.end())
                check_cycle = true;
            else
                visited.insert(cur);
          cur = cur->next;
        } while(cur->next && !(check_cycle));
        return check_cycle;
    }
};