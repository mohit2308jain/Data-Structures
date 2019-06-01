#include <iostream>
#include <list>
#include <stack>
 
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

    void topologicalUtil(int vertex, bool visited[], stack<int> &s){
        visited[vertex]=true;

        list<int>::iterator i;
        for(i=adjLists[vertex].begin(); i!=adjLists[vertex].end();i++){
            int a = *i;
            if(!visited[a]){
                topologicalUtil(a,visited,s);
            }
        } 
        s.push(vertex);  
    }

    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one
    void topological(){

        stack<int> s;

        bool *visited = new bool[numVertices];
        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }


        for(int i=0;i<numVertices;i++){
            if(visited[i]==false){
                topologicalUtil(i,visited,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()+1<<" ";
            s.pop();
        }

    }
};

int main()
{
    Graph g(8);
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
  
    cout << "Following is Depth First Traversaln"; 
    g.topological(); 
 
 
    return 0;
}