#include <iostream>
#include <list>
 
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

    void DFSUtil(int vertex, bool visited[]){
        visited[vertex]=true;

        list<int>::iterator i;
        for(i=adjLists[vertex].begin(); i!=adjLists[vertex].end();i++){
            int a = *i;
            if(!visited[a]){
                DFSUtil(a,visited);
            }
        }   
    }



    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one
    int findMother(){
        bool *visited = new bool[numVertices];

        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }

        int v=0;

        // Do a DFS traversal and find the last finished 
        // vertex 
        for(int i=0;i<numVertices;i++){
            if(visited[i]==false){
                DFSUtil(i,visited);
                v=i;
            }
        }

        // If there exist mother vertex (or vetices) in given 
        // graph, then v must be one (or one of them) 
      
        // Now check if v is actually a mother vertex (or graph 
        // has a mother vertex).  We basically check if every vertex 
        // is reachable from v or not. 
      
        // Reset all values in visited[] as false and do  
        // DFS beginning from v to check if all vertices are 
        // reachable from it or not. 

        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }

        DFSUtil(v, visited);

        for(int i=0;i<numVertices;i++){
            if(visited[i]==false) return-1;
        }
        return (v+1);

    }
};

int main()
{
    Graph g(7);
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(5, 2); 
    g.addEdge(7, 5); 
    g.addEdge(6, 7);
    g.addEdge(6, 3);
    g.addEdge(7, 1); 
  
    cout << "Mother vertex s  : "<<g.findMother(); 
 
 
    return 0;
}