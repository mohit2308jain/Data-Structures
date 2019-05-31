#include<iostream>
#include<vector>
using namespace std;

/* Adjacency Matrix */
int main(){
	int nodes,edges,x,y,i,j;
	cin>>nodes>>edges;

	int amat[10][10];
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			amat[i][j]=0;
		}
	}

	for(i=1;i<=nodes;i++){
		for(j=1;j<=edges;j++){
			cin>>x>>y;
			amat[x][y]=1;
		}
	}
	
	for(i=1;i<=nodes;i++){
		for(j=1;j<=edges;j++){
			cout<<amat[i][j]<<" ";
		}
		cout<<endl;
	}

	// To check for edge between any 2 nodes 

	
	if(amat[4][3]==1) cout<<"There's a edge between x and y";
	else cout<<"No edge between x and y";

	return 0;
}

/* Adjacency List */
int  main(){
	vector<int> adj[10];
	int i,j,x,y,nodes,edges;
	cin>>nodes>>edges;

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