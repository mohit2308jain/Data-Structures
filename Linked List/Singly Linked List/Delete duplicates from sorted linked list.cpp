

// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *p,*q;
    p=head;
    if(p==NULL){
        return NULL;
    }
    while(p->next!=NULL){
        if(p->data == p->next->data){
            q=p->next->next;
            free(p->next);
            p->next=q;
        }
        else{
            p=p->next;
        }
    }
    return head;
}

