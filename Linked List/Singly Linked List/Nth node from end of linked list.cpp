int getNthFromLast(Node *head, int n)
{
    int c=0,i,k;
    Node *p = head;
    while(p){
        p=p->next;
        c++;
    }
    if(n>c || n<=0){
        return -1;
    }
    p=head;
    if(n==c){
        k=head->data;
    }
    else{
        for(i=1;i<=(c-n);i++){
            p=p->next;
        }
        k=p->data;
    }
    return k;
}
