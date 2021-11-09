// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Nov 2021
//  @Detail  :        Copy List with Random Pointer (LeetCode)
//  ============================
//  -->

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   // very very important condition
            return NULL;
//         Create new nodes and connect next pointers
        Node *cur = head;
        while(cur)
        {
            Node *temp = new Node(cur -> val);
            temp -> next = cur -> next;
            cur -> next = temp;
            cur = cur -> next -> next;
        }
        
//         connect random pointers
        cur = head;
            while(cur)
            {
                if(cur -> random)   // very very important condition
                    cur -> next -> random = cur -> random -> next;
                cur = cur -> next -> next;
            }
        
//         detach both the linked lists
        cur = head;
        Node *dummy, *newHead;
        newHead = dummy = head -> next;
        while(cur)
        {
            cur -> next = cur -> next -> next;
            if(dummy -> next)   // very very important condition
                dummy -> next = dummy -> next -> next;
            cur = cur -> next;
            dummy = dummy -> next;
        }
        return newHead;
    }
};
