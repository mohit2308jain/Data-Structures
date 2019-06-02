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
    vector<int> indegree;

    public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];

        for(int i=0;i<numVertices;i++){
            indegree.push_back(0);
        }
    }


    void addEdge(int src, int dest){
        src--;
        dest--;

        adjLists[src].push_back(dest);
        indegree[dest]++;
    }

    void allTopologicalUtil(vector<int> &result, bool visited[]){
        bool flag = false;

        for(int i=0;i<numVertices;i++){
            if(indegree[i]==0 && !visited[i]){
                list<int>::iterator j;
                for(j=adjLists[i].begin();j!=adjLists[i].end();j++){
                    int a = *j;
                    indegree[a]--;
                }

                result.push_back(i);
                visited[i]=true;

                allTopologicalUtil(result,visited);

                //resetting visited and res and indegree for backtracking

                visited[i]=false;
                result.erase(result.end()-1);
                for(j = adjLists[i].begin();j!=adjLists[i].end();j++){
                    int a = *j;
                    indegree[a]++;
                }

                flag=true;


            }
        }

        if(!flag){
            for(int i=0;i<result.size();i++){
                cout<<result[i]+1<<" ";
            }
            cout<<endl;
        }
    }

    void allTopological(){
        bool *visited = new bool();
        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }

        vector<int> result;
        allTopologicalUtil(result, visited);
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

    cout << "All Topological sorts\n";

    g.allTopological();


    return 0;
}
