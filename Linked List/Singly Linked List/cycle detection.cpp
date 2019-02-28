bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *p,*n;
    p=head;
    n=head;
    while(p!=NULL && n!=NULL && n->next!=NULL){
        p=p->next;
        n=n->next->next;
        if(p==n){
            return true;
        }
    }
    return false;


}
