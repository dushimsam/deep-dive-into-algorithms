#include <bits/stdc++.h>
using namespace std;

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

    void BFS(int v)
    {
        queue<int> qu;
        visited[v] = true;
        qu.push(v);

        list<int>::iterator i;
        while (!qu.empty())
        {
            v = qu.front();
            cout << v << endl;
            qu.pop();

            for (i = adj[v].begin(); i != adj[v].end(); i++)
            {
                if (visited[*i])
                    continue;
                qu.push(*i);
                visited[*i] = true;
            }
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

    graph.BFS(2);
    return 0;
}