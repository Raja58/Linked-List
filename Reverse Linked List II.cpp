// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Reverse Linked List II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head -> next)
            return head;
        ListNode * pre = NULL, *cur = head;
        while(cur)
        {
            ListNode *nex = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head -> next || left == right)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *prev = dummy, *start = head, *end = head;
        int idx = 1;
        for(idx = 1; idx < left; idx++)
        {
            prev = start;
            start = start -> next;
        }
            
        end = start;
        for(;idx < right; idx++)
            end = end -> next;
        
        ListNode *backHead = end -> next;
        end -> next = NULL;
        prev -> next = NULL;
        ListNode *middle = reverse(start);
        prev -> next = middle;
        start -> next = backHead;
        return dummy -> next;
    }
};
