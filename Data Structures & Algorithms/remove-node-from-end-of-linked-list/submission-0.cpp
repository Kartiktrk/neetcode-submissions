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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = 0;
        ListNode* first, *second, *prev;
        prev = nullptr;
        first = head;
        second = nullptr;
        while(first){
            first = first -> next;
            pos++;
            if(pos >= n) {
                if(second){
                    prev = second;
                    second = second -> next;
                }
                else second = head;
            }
        }
        if(prev){
            prev -> next = (second) ? second -> next : nullptr;
        }
        else return head -> next;
        return head;
    }
};

// 1 2 3 4 
