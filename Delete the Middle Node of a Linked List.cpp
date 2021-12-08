// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        08 Dec 2021
//  @Detail  :        Delete the Middle Node of a Linked List (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next)
            return NULL;
            
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        prev -> next = prev -> next -> next;
        return head;
    }
};
