// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Nov 2021
//  @Detail  :        Reverse Nodes in k-Group (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)
            return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *pre , *cur, *nex;
        pre = nex = dummy;
        cur = head;
        
        int cnt = 0;
        while(cur)
        {
            cnt++;
            cur = cur -> next;
        }
        
        while(cnt >= k)
        {
            cur = pre -> next;
            nex = cur -> next;
            for(int i = 1; i < k; i++)
            {
                cur -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = cur -> next;
            }
            pre = cur;
            cnt -= k;
        }
        return dummy -> next;
    }
};
