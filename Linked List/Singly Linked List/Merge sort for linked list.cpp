struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */
void split(Node *head,Node** a,Node** b){
    Node* s = head;
    Node* f = head->next;
    while(f){
        f=f->next;
        if(f){
            s=s->next;
            f=f->next;
        }
    }
    *a = head;
    *b = s->next;
    s->next=NULL;
}
Node *merge(Node* a,Node* b){
    Node *res=NULL;
    if(!a) return b;
    else if (!b) return a;
    else{
        if(a->data <= b->data){
            res = a;
            res->next = (merge(a->next,b));
        }
        else{
            res = b;
            res->next = (merge(a,b->next));
        }
    }
    return res;
}
Node* mergeSort(Node* head) {
    Node *a,*b,*h=head;
    if(!head || !head->next) return head;
    
    split(h,&a,&b);
    
    a=mergeSort(a);
    b=mergeSort(b);
    
    return(merge(a,b));
}
