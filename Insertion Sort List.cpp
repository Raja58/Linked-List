// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Insertion Sort List (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        
        ListNode *dummy = new ListNode(INT_MIN), *tail = head, *cur = head -> next;
        dummy -> next = head;
        
        while(cur != NULL)
        {
            if(cur -> val >= tail -> val)
            {
                tail = tail -> next;
                cur = tail -> next;
                continue;
            }
            
            tail -> next = cur -> next;
            cur -> next = NULL;
            
            ListNode *temp = dummy;
            while(temp -> next -> val < cur -> val)
                temp = temp -> next;
            
            cur -> next = temp -> next;
            temp -> next = cur;
            cur = tail -> next;
        }
        return dummy -> next;
    }
};
