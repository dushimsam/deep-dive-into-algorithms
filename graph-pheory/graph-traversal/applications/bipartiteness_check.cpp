#include <bits/stdc++.h>
using namespace std;

/***
 *  Visit all the nodes assigning them colors
 *  if the two nodes are visited and they share colors
 *  then  immediately conclude bipartiness to be false.
 * 
***/
class Graph
{
    vector<bool> visited;
    map<int, list<int>> adj;

public:
    Graph(int n)
    {
        visited.resize(n);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool isBipartile(int v, vector<int>& colors)
    {
        list<int>::iterator it;
        visited[v] = true;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it])
            {
                colors[*it] = !colors[v];
                if(!isBipartile(*it,colors)){
                   return false;
                }
            }
            else if (colors[*it] == colors[v])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int N = 6;
    Graph graph(N);

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 7}, {2, 3}, {3, 5}, {4, 6}, {4, 8}, {7, 8}, {1, 3}
        // if we remove (1, 3) edge, the graph becomes bipartite
    };
    
    for (int i = 0; i < edges.size(); i++)
    {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    vector<int> colors(N);
    colors[1] = 0;
    // check if the graph is not bipartile or not

    if (graph.isBipartile(1, colors))
    {
        cout << "The graph is bipartile";
    }
    else
    {

        cout << "The graph is not bipartile";
    }
    return 0;
}