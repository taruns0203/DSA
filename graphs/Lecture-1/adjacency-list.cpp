#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected Graph
        // direction = 1 -> directed Graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbours : node.second)
            {
                cout << neighbours << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // int n;
    // cout << "Enter the number of nodes: " << endl;
    // cin >> n;

    // int e;

    Graph g;

    // undorected edgeinput
    //  g.addEdge(0,1,0);
    //  g.addEdge(1,2,0);
    //  g.addEdge(0,2,0);
    //  cout << endl;
    //  g.printAdjacencyList();

    // directed input
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);
    cout << endl;
    g.printAdjacencyList();

    return 0;
}
