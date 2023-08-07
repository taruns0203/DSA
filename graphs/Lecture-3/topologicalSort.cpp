#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
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

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                topoSortDfs(neighbour, visited, ans);
            }
        }

        // while returning, store the node in stack
        ans.push(src);
    }
};

int main()
{

    // to insert int type of data
    // Graph<int> g;

    // to insert char type data
    int n = 8;
    Graph<int> q;
    q.addEdge(0, 1, 1);
    q.addEdge(1, 2, 1);
    q.addEdge(2, 3, 1);
    q.addEdge(3, 4, 1);
    q.addEdge(3, 5, 1);
    q.addEdge(4, 6, 1);
    q.addEdge(5, 6, 1);
    q.addEdge(6, 7, 1);
    q.printAdjacencyList();
    cout << endl;

    unordered_map<int, bool> visited;
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            q.topoSortDfs(i, visited, ans);
        }
    }

    cout << "Topo Sort : " << endl;
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}
