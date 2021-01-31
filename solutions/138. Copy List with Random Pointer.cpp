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
​
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* l1 = head;
        Node* l2 = NULL;
        while(l1) {
            l2 = new Node(0);
            l2->val = l1->val;
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }
        l1 = head;
        while(l1) {
            l2 = l1->random;
            l2->random = l2->next != NULL ? l2->next->random : NULL;
            l1 = l1->next;
        }
        l1 = head;
        Node* l2_head = l1->random;
        while(l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next != NULL ? l1->next->random : NULL;
            l1 = l1->next;
        }
        return l2_head;
    }
};
