#include <bits/stdc++.h>
using namespace std;

/***
 *                APPROACH
 * 1. Apply Depth search that visits all the nodes of the graph
 * Then if one of the nodes is found not have been visited
 * it means that the graph is not strong ly connnected.
 *
 ***/

class Graph
{

    vector<bool> visited;
    int n;
    map<int, list<int>> adj;

public:
    Graph(int n){
        this->n = n;
        visited.resize(n);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void DFS(int v)
    {
        visited[v] = true;
        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
                DFS(*i);
        }
    }

    bool isStronglyConnected()
    {
        ///  CHECK IF YOU CAN TRAVERSE THE WHOLE GRAPH STARTING FROM EACH NODE.
        // IF YOU COMPLETE TRAVERSING A PARTICULAR NODE AND YOU FIND THEY ARE SOME ELEMENTS WHICH WERE NOT REACHED
        // CONCLUDE THAT , IT IS NOT STRONGLY CONNECTED
        
        for (auto v : adj)
        {
            DFS(v.first);
            if (find(visited.begin(), visited.end(), false) != visited.end())
                return false;
        }

        return true;
    }
};
int main()
{
    vector<vector<int>> edges = {{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}};
    Graph graph(5);
    for (int i = 0; i < edges.size(); i++)
    {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    // check if the graph is not strongly connected or not
    if (graph.isStronglyConnected())
    {
        cout << "The graph is strongly connected";
    }
    else
    {

        cout << "The graph is not strongly connected";
    }

    return 0;
}