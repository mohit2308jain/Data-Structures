/****************************************

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. 
The sum list which is a linked list representation of addition of two input numbers.

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7

Output:
0 9 3  
0 7

Explaination:
5->4 // linked list repsentation of 45.
5->4->3 // linked list representation of 345.
0->9 ->3 // linked list representation of 390 resultant linked list.
*****************************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* addTwoLists(struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        cout<<Node->data<<" ";
        Node = Node->next;
    }
    cout<<endl;
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node *reverse(Node* head){
    Node *p=NULL,*n=NULL,*cur=head;
    while(cur){
        n = cur->next;
        cur->next=p;
        
        p = cur;
        cur = n;
    }
    head = p;
    return head;
}
Node* addTwoLists(Node* first, Node* second) {
    long long f=0,s=0,a,b;
    
    Node *third = NULL;
    
    while(first || second){
        if(first) a = first->data;
        else a=0;
        
        if(second) b = second->data;
        else b = 0;
        
        s = f + a + b;
        
        if(s>=10) f=1;
        else f=0;
        
        s = s%10;
        
        push(&third,s);
        
        if(first) first=first->next;
        
        if(second) second=second->next;
    }
    
    if(f>0) push(&third,f);
    
    third = reverse(third);
    return third;
}
