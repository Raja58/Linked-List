// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        2.0
//  @Date    :        29 Dec 2021
//  @Detail  :        Reverse Nodes in k-Group (LeetCode)
//  ============================
//  -->


class Solution {
public:
    
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head -> next)
            return head;
        ListNode *prev = NULL, *cur = head;
        while(cur)
        {
            ListNode *nex = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head || !head -> next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *pivot = dummy, *prev = dummy, *cur = head;
        while(cur != NULL)
        {
            for(int i = 0; i < k && prev != NULL; i++)
            {
                prev = cur;
                if(cur != NULL)
                    cur = cur -> next;
            }
            if(prev == NULL)
                return dummy -> next;
            prev -> next = NULL;
            ListNode *revHead = reverse(pivot -> next);
            pivot -> next -> next = cur;
            prev = pivot -> next;
            pivot -> next = revHead;
            pivot = prev;
        }
        return dummy -> next;
    }
};
