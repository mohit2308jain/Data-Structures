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

        cout<<vertex+1<<" ";

        list<int>::iterator i;
        for(i=adjLists[vertex].begin(); i!=adjLists[vertex].end();i++){
            int a = *i;
            if(!visited[a]){
                DFSUtil(a,visited);
            }
        }   
    }

    // DFS traversal of the vertices reachable from v. 
    // It uses recursive DFSUtil() 
    void DFS(int v){
        v--;
        bool *visited = new bool[numVertices];
        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }

        
        DFSUtil(v,visited);

    }

    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one
    void DFS(){
        bool *visited = new bool[numVertices];
        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }


        for(int i=0;i<numVertices;i++){
            if(visited[i]==false){
                DFSUtil(i,visited);
            }
        }

    }
};

int main()
{
    Graph g(4);
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.addEdge(3, 4); 
    g.addEdge(4, 4); 
  
    cout << "Following is Depth First Traversaln"; 
    g.DFS(3); 
 
 
    return 0;
}