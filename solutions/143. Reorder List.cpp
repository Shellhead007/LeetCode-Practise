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
    void reverseList(ListNode** head)
    {
        ListNode* curr = *head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head = prev;
    }
    void reorderList(ListNode* head) 
    {
        if(head==NULL)
            return;
        
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;
        reverseList(&head2);
        
        head = new ListNode(0);          // dummy node
        ListNode* curr = head;
        while(head1 || head2)
        {
            if(head1)
            {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
            
            if(head2)
            {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
        head = head->next;
    }
};
