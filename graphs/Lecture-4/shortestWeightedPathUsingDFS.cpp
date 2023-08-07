#include <iostream>
#include <queue>
#include <unordered_map>
#include <stack>
#include <list>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected graph
        // direction = 0 -> directed graph
        adjList[u].push_back({v, wt});
        if (direction == 0)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        // while returning, store the node in stack
        cout << "Pushing " << src << endl;
        ans.push(src);
    }

    void shortestpathDfs(int dest, stack<int> topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbr : adjList[0])
        {
            if (dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {

            int topElement = topoOrder.top();
            topoOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto nbr : adjList[topElement])
                {
                    if (dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing Ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> " << dist[i] << endl;
        }
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, 5, 0);
    g.addEdge(0, 2, 3, 0);
    g.addEdge(2, 1, 2, 0);
    g.addEdge(1, 3, 3, 0);
    g.addEdge(2, 3, 5, 0);
    g.addEdge(2, 4, 6, 0);
    g.addEdge(4, 3, 1, 0);

    g.printAdjList();

    stack<int> topoOrder;
    unordered_map<int, bool> visited;

    g.topoSortDfs(0, visited, topoOrder);

    g.shortestpathDfs(3, topoOrder, 5);

    // int src = 0;
    // int dest = 4;
    // g.printAdjList();
    // g.shortestPathBfs(src, dest);
}