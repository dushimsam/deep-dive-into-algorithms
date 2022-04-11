#include <bits/stdc++.h>
using namespace std;

/***
 * NODES :
 * Distinct elements in the given  list (refer to a vector list in the main function)
 * NUMBER OF NODES:
 * The side of the adj list.
***/
class Graph
{
    vector<bool> visited;
    map<int, list<int>> adj;

public:
    Graph(int n){
        visited.resize(n);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void DFSUtil(int v)
    {
        visited[v] = true;
        list<int>::iterator i;
        cout << v << endl;

        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
                DFSUtil(*i);
        }
    }

    void DFS()
    {
        // We place this loop because we are not sure
        // if the graph is strongly connected.
        // So to reach all the elements we should
        // visit each vertex in the adj list.

        for (auto i : adj)
        {
            if(visited[i.first] == false) DFSUtil(i.first);
        }
        
    }
};

int main()
{

    Graph graph(5);
    vector<vector<int>> adj = {{0, 1}, {0, 9}, {1, 2}, {2, 0}, {2, 3}, {9, 3}};
    for (int i = 0; i < adj.size(); i++)
    {
        graph.addEdge(adj[i][0], adj[i][1]);
    }
    graph.DFS();
    return 0;
}