#include<iostream>
#include<vector>
using namespace std;

void BFS(int amat[20][20], int nodes, int startindex){
	int i,j;
	bool flag = false;

	int visited[nodes+1];
	int top = 1;
	int stack[nodes+1];

	for(i=1;i<=nodes;i++){
		visited[i]=0;
	}
	visited[startindex]=1;
	stack[top] = startindex;
	cout<<startindex<<" ";

	while(top>=1){
		flag = false;

		i = stack[top];

		for(j=1;j<=nodes;j++){
			if(visited[j]==0 && amat[i][j]==1){
				visited[j]=1;

				top++;
				stack[top]=j;

				cout<<j<<" ";

				flag = true;

				break;
			}
		}
		if(flag==false){
			top--;
		}
	}
	cout<<endl;

}

int main(){
	int nodes,x,y,i,j;
	cin>>nodes;
	
	int amat[20][20];
	
	for(i=1;i<=nodes;i++){
		for(j=1;j<=nodes;j++){
			amat[i][j]=0;
		}
	}

	int f=1;
	for(i=1;i<=nodes;i++){
		for(j=1;j<=nodes;j++){
			cin>>x>>y;
			if(x==-1 || y==-1){
				f=0;
				break;
			}
			amat[x][y]=1;
		}
		if(f==0) break;
	}
	
	for(i=1;i<=nodes;i++){
		for(j=1;j<=nodes;j++){
			cout<<amat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	int startindex;
	cin>>startindex;
	BFS(amat,nodes,startindex);

	return 0;
}