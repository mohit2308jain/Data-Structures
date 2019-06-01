#include<iostream>
#include<vector>
using namespace std;

/* Adjacency Matrix */
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

	return 0;
}
/* Adjacency List */
int  main(){
	vector<int> adj[10];
	int i,j,x,y,nodes,edges;
	cin>>nodes;

	for(i=1;i<=edges;i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}

	for(i=1;i<=nodes;i++){
		cout<<"Adjacency list of node "<<i<<" : ";
		for(j=0;j<adj[i].size();j++){
			if(j==adj[i].size()-1){
				cout<<adj[i][j]<<endl;
			}
			else{
				cout<<adj[i][j]<<"---->";
			}
		}
		cout<<endl;
	}

	return 0;
}