// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Split Linked List in Parts (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode *cur = head;
        while(cur)
        {
            len++;
            cur = cur -> next;
        }
        
        int cnt = len / k, extra = len % k;
        vector<ListNode *> result(k);
        cnt++;
        
        cur = head;
        for(int i = 0; i < k; i++)
        {
            if(i == extra)
                cnt--;
            
            if(!cur)
            {
                result[i] = NULL;
                continue;
            }
            
            result[i] = cur;
            ListNode *temp = cur;
            for(int i = 0; i < cnt - 1; i++)
                temp = temp -> next;
            cur = temp -> next;
            temp -> next = NULL;
        }
        return result;
    }
};
