/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* curr = head;
        ListNode* temp = head;
        while(curr && curr->next) {
            if(curr->val == curr->next->val) {
                temp = curr;
                while(curr && curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                if(temp == head) {
                    head = curr->next;
                } else {
                    ListNode* p = head;
                    while(p->next!=NULL) {
                        p = p->next;
                    }
                    p->next = curr->next;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
