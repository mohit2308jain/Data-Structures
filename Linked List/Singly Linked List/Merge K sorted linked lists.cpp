/**********************************************************

Merge K sorted linked lists

*********************************************************/

#include <bits/stdc++.h>

using namespace std;
struct node{
    int f;
    struct node* next;
};
void push(struct node** head,int d){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->f=d;
    t->next=*head;
    *head=t;
}
struct node* merge(struct node* a,struct node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    struct node *res=NULL;
    if(a->f <= b->f){
        res=a;
        res->next=(merge(a->next,b));
    }
    else{
        res=b;
        res->next=(merge(a,b->next));
    }
    
    return res;
}
struct node* mergek(struct node* arr[],int l){
    while(l!=0){
        int i=0,j=l;
        while(i<j){
            arr[i]=merge(arr[i],arr[j]);
            i++;
            j--;
            if(i>=j){
                l=j;
            }
        }
    }
    return arr[0];
}
void print(struct node* h){
    struct node* j = h;
    while(j!=NULL){
        cout<<j->f<<" ";
        j=j->next;
    }
}
int main()
{
    int t;
    cin>>t;
    struct node *a[t],*c=NULL;
    for(int j=0;j<t;j++){
        a[j]=NULL;
    }
    int n,k;
    for(int j=0;j<t;j++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>k;
            push(&a[j],k);
        }
    }
    
    c = mergek(a,t-1);
    print(c);
    
    return 0;
}
