#include <iostream>
#include <list>
 
using namespace std;
 
class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool* visited;
    
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
    void BFS(int startVertex){
    	startVertex--;

    	visited = new bool[numVertices];

    	for(int i = 0; i < numVertices; i++)
    		visited[i] = false;
 
	    list <int>queue;
 
    	visited[startVertex] = true;
    	queue.push_back(startVertex);
 
    	list<int>::iterator i;
 
    	cout << "Visited : ";
    	while(!queue.empty()){
        	int currVertex = queue.front();
        	cout << currVertex+1 << " ";
        	queue.pop_front();
 
        	for(i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        	{
            	int adjVertex = *i;
            	if(!visited[adjVertex])
            	{
            		visited[adjVertex] = true;
                	queue.push_back(adjVertex);
            	}
        	}
    	}
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);    
    g.addEdge(3, 5);

    g.BFS(1);
 
 
    return 0;
}