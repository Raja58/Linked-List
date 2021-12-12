// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Sort List (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1), *tail;
        tail = dummy;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> val <= head2 -> val)
            {
                tail -> next = head1;
                head1 = head1 -> next;
            }
            else
            {
                tail -> next = head2;
                head2 = head2 -> next;
            }
            tail = tail -> next;
        }
        
        if(head1 != NULL)
            tail -> next = head1;
        if(head2 != NULL)
            tail -> next = head2;
        return dummy -> next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *prev = NULL, *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        return merge(head, slow);
    }
};
