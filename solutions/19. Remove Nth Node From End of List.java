/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null)
            return null;
        ListNode temp1 = head;
        ListNode temp2 = head;
        
        for(int i=0;i<n;i++)
            temp1 = temp1.next;
        if(temp1 == null)
            return head.next;
        while(temp1.next!=null) {
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        
        temp2.next = temp2.next.next;
        return head;
    }
}
