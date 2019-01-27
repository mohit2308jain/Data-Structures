

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *newnode=(DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode)),*p;
    newnode->data=data;
    if(head==NULL){
        newnode->next=head;
        head=newnode;
    }else if(head->data >= newnode->data){
        newnode->next=head;
        newnode->next->prev=newnode;
        head=newnode;
    }
    else{
        p=head;
        while(p->next!=NULL && p->next->data < newnode->data){
            p=p->next;
        }
        newnode->next=p->next;
        if(p->next!=NULL){
            (p->next)->prev = newnode;
        }
        p->next=newnode;
        newnode->prev = p;
    }
    

    return head;

}

