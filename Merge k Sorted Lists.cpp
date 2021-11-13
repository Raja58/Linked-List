// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Nov 2021
//  @Detail  :        Merge k Sorted Lists (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        ListNode *node;
        bool operator<(const detail &x) const{
            return node -> val > x.node -> val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<detail> cache;
        ListNode *dummy = new ListNode(-1), *tail = new ListNode(-1);
        tail = dummy;
        
        for(ListNode* x : lists)
            if(x)
                cache.push({x});
        
        while(!cache.empty())
        {
            detail temp = cache.top();   cache.pop();
            tail -> next = temp.node;
            tail = tail -> next;
            if(temp.node -> next)
                cache.push({temp.node -> next});
        }
        return dummy -> next;
    }
};
