#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
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

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            // insert neighbours
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{

    // to insert int type of data
    // Graph<int> g;

    // to insert char type data
    Graph<int> q;
    q.addEdge(0, 1, 0);
    q.addEdge(1, 2, 0);
    q.addEdge(1, 3, 0);
    q.addEdge(3, 5, 0);
    q.addEdge(3, 7, 0);
    q.addEdge(7, 6, 0);
    q.addEdge(7, 4, 0);
    q.printAdjacencyList();
    cout << endl;

    unordered_map<int, bool> visited;
    for (int i = 0; i <= 7; i++)
    {
        if (!visited[i])
        {
            q.bfs(i, visited);
        }
    }
    // q.bfs(0);

    return 0;
}
