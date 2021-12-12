// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Flatten a Multilevel Doubly Linked List (LeetCode)
//  ============================
//  -->

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while(cur)
        {
            if(cur -> child == NULL)
            {
                cur = cur -> next;
                continue;
            }
            
            Node *potenNext = flatten(cur -> child);
            Node *temp = potenNext;
            while(temp -> next != NULL)
                temp = temp -> next;
            
            cur -> child = NULL;
            potenNext -> prev = cur;
            temp -> next = cur -> next;
            if(cur -> next)
                cur -> next -> prev = temp;
            cur -> next = potenNext;
            
            cur = temp -> next;
        }
        return head;
    }
};
