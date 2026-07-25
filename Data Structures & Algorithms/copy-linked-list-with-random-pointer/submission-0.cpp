
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head1) {
        map<Node*,Node*> mp;
        Node* head = head1;
        if(!head) return nullptr;
        Node* deepHead = new Node(head1 -> val);
        Node* prev = deepHead;
        mp[head] = deepHead;
        head = head -> next;
        while(head){
            prev -> next =  new Node(head -> val);
            prev = prev -> next;
            mp[head] = prev;
            head = head -> next;
        }
        Node* deepHead1 = deepHead;
        while(head1){
            if(head1 -> random == nullptr){
                head1 = head1 -> next;
                deepHead1 = deepHead1 -> next;
                continue;
            }
            deepHead1 -> random = mp[head1->random];
            head1 = head1 -> next;
            deepHead1 = deepHead1 -> next;
        }

        return deepHead;

    }
};