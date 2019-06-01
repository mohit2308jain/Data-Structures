#include<iostream>
#include<vector>
using namespace std;

int queue[20],queue_end=0,queue_front=-1;

void enqueue(int v){
	if(queue_front==-1){
		queue_front=0;
	}
	queue[queue_end] = v;
	queue_end++;
}

int dequeue(){
	int i = queue_front;
	queue_front++;
	return queue[i];
}

int isempty(){
	if(queue_front==-1 || queue_front > queue_end){
		return 1;
	}
	else return 0;
}

int indeg(int amat[20][20], int nodes,int vertex){
	int co,totindeg=0;
	for(co=1;co<=nodes;co++){
		if(amat[co][vertex]==1){
			totindeg++;
		}
	}
	return totindeg;
}

int main(){
	int nodes,x,y,i,j;
	cin>>nodes;

	int amat[20][20],indegree[nodes+1],topo[nodes+1];

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

	for(i=1;i<=nodes;i++){
		indegree[i]=indeg(amat,nodes,i);
		if(indegree[i]==0){
			enqueue(i);
		}
	}

	int count=0,vv;
	while(!isempty() && count < nodes){
		vv = dequeue();
		topo[++count]=vv;
		for(i=1;i<=nodes;i++){
			if(amat[vv][i]==1){
				amat[vv][i]=0;
				indegree[i] -= 1;
				if(indegree[i]==0){
					enqueue(i);
				}
			}
		}
	}

	for(i=1;i<=nodes;i++){
		cout<<topo[i]<<" ";
	}


	return 0;
}
