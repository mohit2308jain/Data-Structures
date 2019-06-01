#include<iostream>
#include<vector>
using namespace std;

int queue[20],queue_end,queue_front;

void enqueue(int v){
	queue[queue_end] = v;
	queue_end++;
}

int dequeue(){
	int i = queue_front;
	queue_front++;
	return queue[i];
}

void BFS(int amat[20][20], int nodes, int startindex){
	int i,j;

	queue_end=0;
	queue_front=0;

	int visited[nodes+1];

	for(i=1;i<=nodes;i++){
		visited[i]=0;
	}

	visited[startindex]=1;
	enqueue(startindex);

	cout<<startindex<<" ";

	while(queue_front <= queue_end){
		i = dequeue();

		for(j=1;j<=nodes;j++){
			if(visited[j]==0 && amat[i][j]==1){
				visited[j]=1;
				enqueue(j);
				cout<<j<<" ";
			}
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