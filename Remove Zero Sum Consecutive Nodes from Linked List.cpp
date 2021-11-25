// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Remove Zero Sum Consecutive Nodes from Linked List (LeetCode)
//  ============================
//  -->

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *cur = head;
        int sum = 0;
        unordered_map<int, ListNode*> cache;
        cache[0] = dummy;
        while(cur)
        {
            sum += cur -> val;
            if(cache.find(sum) == cache.end())
            {
                cache[sum] = cur;
                cur = cur -> next;
                continue;
            }
            
            ListNode *prev = cache[sum];
            ListNode *temp = prev -> next;
            
            int poten = sum;
            while(temp != cur)
            {
                poten += temp -> val;
                cache.erase(poten);
                temp = temp -> next;
            }
            prev -> next = cur -> next;
            cur = cur -> next;
        }
        return dummy -> next;
    }
};
