//HEAD

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

//BODY

struct stackNode{
    int val;
    struct stackNode* next;
};
typedef struct stackNode stackNode;
stackNode* stackHead;
int empty();
void push(int x)
{
    stackNode *newnode = (stackNode*)malloc(sizeof(stackNode));
    newnode->val=x;
    newnode->next=stackHead;
    stackHead=newnode;
}
int peek()
{
    int x=(stackHead->val);
    return x;
}
void pop(){
    stackNode *p;
    p=stackHead;
    if(!empty()){
        stackHead = p->next;
        free(p);
    }
 
}
int empty(){
    if(stackHead==NULL)
        return 1;
    else 
        return 0;
}

//TAIL

int main()
{
    int n;
    stackHead = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t, x;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            push(x);
        }
        else if (t == 2) {
            if (empty()) {
                printf("Invalid\n");
            }
            else {
                pop();
            }
        }
        else if (t == 3){
            if (empty()) {
                printf("Invalid\n");
                continue;
            }
            stackNode* j = stackHead;
            while (j) {
                printf("%d ", j->val);
                j = j->next;
            }
            printf("\n");
        }
        else {
            if (empty()) {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", peek());
        }
    }
    return 0;
}