// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Remove Duplicates from Sorted List II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *tail = dummy;
        while(tail -> next != NULL)
        {
            ListNode *start = tail -> next, *end = tail -> next;
            while(end -> next && end -> next-> val == start -> val)
                end = end -> next;
            
            if(start == end)
            {
                tail = tail -> next;
                continue;
            }
            
            tail -> next = end -> next;
        }
        return dummy -> next;
    }
};
