// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Add Two Numbers II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head -> next)
            return head;
        ListNode *cur = head, *pre = NULL;
        while(cur)
        {
            ListNode *nex = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0;
        ListNode *i = l1, *j = l2, *head = NULL;
        while(i || j || carry)
        {
            int sum = carry;
            if(i)
            {
                sum += i -> val;
                i = i -> next;
            }
            if(j)
            {
                sum += j -> val;
                j = j -> next;
            }
            
            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;
            
            if(!head)
            {
                head = temp;
                continue;
            }
            
            temp -> next = head;
            head = temp;
        }
        return head;
    }
};
