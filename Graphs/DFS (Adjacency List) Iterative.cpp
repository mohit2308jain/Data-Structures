#include <iostream>
#include <list>
#include <vector>
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
        adjLists = new list<int>[numVertices];
    }


    void addEdge(int src, int dest){
        src--;
        dest--;

        adjLists[src].push_back(dest);
    }

    void DFS(int w){
        w--;
        vector<int> visited(numVertices,false);

        stack<int> s;

        s.push(w);

        while(!s.empty()){
            int v = s.top();
            s.pop();

            if(!visited[v]){
                cout<<v+1<<" ";
                visited[v]=true;
            }

            list<int>::iterator i;
            for(i = adjLists[v].begin();i!=adjLists[v].end();i++){
                if(!visited[*i]){
                    s.push(*i);
                }
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
