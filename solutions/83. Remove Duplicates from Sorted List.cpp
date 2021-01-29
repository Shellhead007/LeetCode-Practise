/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* next_to_current;
        
        if(current==NULL)
            return NULL;
        
        while(current->next!=NULL)
        {
            if(current->val==current->next->val)
            {
                next_to_current = current->next->next;
                current->next = next_to_current;
             }
            else
                current = current->next;
        }
        return head;
    }
};
