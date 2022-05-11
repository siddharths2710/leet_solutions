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
    int pairSum(ListNode* head) {
        /*
            1. Get len(linked list starting at head)
            2. Create arr of size len/2
            3. traverse from 0 to (n/2 - 1) and add to arr from bottom up
            4. traverse from (n/2) to n - 1 and add to arr from top down
                4.1 Update maximum sum while doing the 2nd traversal
            5. Return final max sum
        */
        int len = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            cur = cur->next;
            len++;
        }
        if(!len) return 0;
        else if(len == 2) return head->val + head->next->val;
        
        int *sums = new int[len >> 1];
        int max_twin_sum = 0;
        cur = head;
        for(int i = 0; i < len >> 1; i++) {
            sums[i] = cur->val;
            cur = cur->next;
        }
        for(int i = len >> 1; i < len; i++) {
            sums[len - 1 - i] += cur->val;
            max_twin_sum = max(max_twin_sum, sums[len - 1 - i]);
            cur = cur->next;
        }
        return max_twin_sum;
    }
};