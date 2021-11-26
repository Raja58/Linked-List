// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Swap Nodes in Pairs (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next)
            return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *cur = head, *prev = dummy;
        while(cur && cur -> next)
        {
            ListNode *nex = cur -> next;
            prev -> next = nex;
            cur -> next = nex -> next;
            nex -> next = cur;
            prev = cur;
            cur = cur -> next;
        }
        return dummy -> next;
    }
};
