#include <iostream>
using namespace std;

struct node{
	int x;
	struct node *l;
	struct node *r;
};

struct node* newnod(int d){
    struct node* newno=(struct node*)malloc(sizeof(struct node));
    newno->x=d;
    newno->l=newno->r=NULL;
    return newno;
}
struct node* insert(struct node* root,int d){
	if(!root){
		return newnod(d);
	}
	else if(root->x >= d){
		root->l = insert(root->l,d);
	}
	else if(root->x < d){
		root->r = insert(root->r,d);
	}

	return root;
}

void findpresuc(struct node* root,struct node*& pre,struct node*& suc, int k){
	if(!root) return;

	if(root->x == k){
		if(root->l){
			struct node* tmp = root->l;
			while(tmp->r){
				tmp = tmp->r;
			}
			pre = tmp;
		}

		if(root->r){
			struct node* tmp = root->r;
			while(tmp->l){
				tmp = tmp->l;
			}
			suc = tmp;
		}
		return;
	}

	if(root->x > k){
		suc = root;
		findpresuc(root->l,pre,suc,k);
	}
	else{
		pre = root;
		findpresuc(root->r,pre,suc,k);
	}
}
void inorder(struct node* eoot){
    if(eoot!=NULL){
        inorder(eoot->l);
        cout<<(eoot->x)<<" ";
        inorder(eoot->r);
    }
}

int main(){
	struct node* root = NULL;
	int n,m,j;
	cin>>n;
	cin>>m;
	root=insert(root,m);
	for(int i=1;i<n;i++){
		cin>>j;
		insert(root,j);
	}

	inorder(root);
	cout<<endl;
	struct node *pre = NULL, *suc = NULL;

	cin >>j;
	findpresuc(root,pre,suc,j);

	if(pre) cout<<"Predecessor of "<<j<<" is "<<pre->x<<endl;
	else cout<<"No Predecessor"<<endl;

	if(suc) cout<<"Successor of "<<j<<" is "<<suc->x<<endl;
	else cout<<"No Successor"<<endl;

	return 0;
}
