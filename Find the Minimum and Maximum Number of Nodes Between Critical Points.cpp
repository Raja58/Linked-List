// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Find the Minimum and Maximum Number of Nodes Between Critical Points (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result{-1, -1};
        if(!head || !head -> next || !head -> next -> next)
            return result;
        vector<int> critical;
        int idx = 1;
        ListNode *pre = head, *cur = head -> next, *nex = head -> next -> next;
        while(nex)
        {
            if(pre -> val < cur -> val && cur -> val > nex -> val)
                critical.push_back(idx);
            else if(pre -> val > cur -> val && cur -> val < nex -> val)
                critical.push_back(idx);
            pre = cur;
            cur = nex;
            nex = nex -> next;
            idx++;
        }
        if(critical.size() <= 1)
            return result;
        result[1] = critical.back() - critical.front();
        int mini = INT_MAX;
        for(int i = 1; i < critical.size(); i++)
            if(mini > critical[i] - critical[i - 1])
                mini = critical[i] - critical[i - 1];
        result[0] = mini;
        return result;
    }
};
