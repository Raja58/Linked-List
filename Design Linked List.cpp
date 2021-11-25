// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Design Linked List (LeetCode)
//  ============================
//  -->

class MyLinkedList {
public:
    
    struct Node{
        int val;
        Node *prev;
        Node *next;
        Node(int x){
            val = x;
            prev = next = NULL;
        }
    };
    
    Node *front = new Node(-1), *back = new Node(-1);
    int size;
    
    MyLinkedList() {
        front -> next = back;
        back -> prev = front;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size)
            return -1;
        Node *temp = front;
        while(index)
        {
            temp = temp -> next;
            index--;
        }
        return temp -> next -> val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        Node *temp = new Node(val);
        temp -> prev = back -> prev;
        temp -> next = back;
        back -> prev -> next = temp;
        back -> prev = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        int idx = 0;
        Node *temp = front, *poten = new Node(val);
        while(idx != index)
        {
            temp = temp -> next;
            idx++;
        }
        Node *nex = temp -> next;
        temp -> next = poten;
        poten -> next = nex;
        nex -> prev = poten;
        poten -> prev = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        Node *temp = front;
        while(index)
        {
            temp = temp -> next;
            index--;
        }
            
        Node *poten = temp -> next;
        temp -> next = temp -> next -> next;
        poten -> next -> prev = temp;
        size--;
        delete(poten);
    }
};
