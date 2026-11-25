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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(!curr || !curr->next) return head;
        ListNode* after = curr->next;
        while( curr )
        {
            curr -> next = prev;
            prev = curr;
            curr = after;
            if(after && after->next) after = after -> next;
            else after = NULL;
        }
        return prev;
    }
};
