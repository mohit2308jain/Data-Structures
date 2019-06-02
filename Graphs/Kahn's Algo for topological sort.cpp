#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
 
using namespace std;
 
class Graph
{
    int numVertices;
    list<int> *adjLists;
    
    public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    } 


    void addEdge(int src, int dest){
        src--;
        dest--;

        adjLists[src].push_back(dest);
    }

    
    void topological(){
        vector<int> indegree(numVertices, 0);

        for(int i=0;i<numVertices;i++){
            list<int>::iterator itr;
            for(itr = adjLists[i].begin();itr!=adjLists[i].end();itr++){
                indegree[*itr]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numVertices;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int co=0;

        vector<int> topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);

            list<int>::iterator itr;
            for(itr = adjLists[u].begin();itr!=adjLists[u].end();itr++){
                if(--indegree[*itr] == 0){
                    q.push(*itr);
                }
            }

            co++;
        }

        if(co!=numVertices){
            cout<<"Cycle"<<endl;
            return;
        }

        for(int i=0;i<topo.size();i++){
            cout<<topo[i]+1<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    /*Graph g(8);
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
    g.addEdge(2, 7); 
    g.addEdge(3, 5);
    g.addEdge(4, 6); 
    g.addEdge(4, 8); 
    g.addEdge(5, 7); 
    g.addEdge(6, 7);
    g.addEdge(6, 8); 
    g.addEdge(7, 8); 
    */

    Graph g(6); 
    g.addEdge(6, 3); 
    g.addEdge(6, 1); 
    g.addEdge(5, 1); 
    g.addEdge(5, 2); 
    g.addEdge(3, 4); 
    g.addEdge(4, 2); 
  
    cout << "Following is Depth First Traversaln"; 
    g.topological(); 
 
 
    return 0;
}