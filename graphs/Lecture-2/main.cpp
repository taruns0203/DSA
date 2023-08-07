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

    bool checkCyclicUsingBfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                if (visited[nbr] && nbr != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDfs(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
                if (checkAageKaAns == true)
                {
                    return true;
                }

                if (visited[nbr] && nbr != parent)
                {
                    // cycle present
                    return true;
                }
            }
        }

        return false;
    }

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited)
    {

        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aageKaAnswer == true)
                {
                    return true;
                }
            }

            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }

        // yahi galti hogi
        dfsVisited[src] = false;
        return false;
    }
};

int main()
{

    // to insert int type of data
    // Graph<int> g;

    // to insert char type data
    int n = 5;
    Graph<int> q;
    q.addEdge(0, 1, 1);
    q.addEdge(1, 2, 1);
    q.addEdge(2, 3, 1);
    q.addEdge(3, 4, 1);
    q.addEdge(4, 0, 1);
    q.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = q.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if (ans == true)
            {
                break;
            }
        }
    }

    if (ans == true)
    {
        cout << "Cycle is Present " << endl;
    }
    else
    {
        cout << " Cycle Absent " << endl;
    }

    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i <= n; i++)
    // {
    //     if (!visited[i])
    //     {
    //          ans = q.checkCyclicUsingBfs(i, visited);
    //         if(ans == true){
    //             break;
    //         }
    //     }
    // }

    // if(ans == true){
    //     cout << "Cycle is Present "<<endl;
    // }else{
    //     cout <<" Cycle Absent " << endl;
    // }

    // bool ansDfs = false;
    // unordered_map<int, bool> visitedDfs;
    // for (int i = 0; i <= n; i++)
    // {
    //     if (!visitedDfs[i])
    //     {
    //          ansDfs = q.checkCyclicUsingDfs(i, visitedDfs,-1);
    //         if(ansDfs == true){
    //             break;
    //         }
    //     }
    // }

    // if(ansDfs == true){
    //     cout << "Cycle DFS is Present "<<endl;
    // }else{
    //     cout <<" Cycle DFS Absent " << endl;
    // }

    return 0;
}
