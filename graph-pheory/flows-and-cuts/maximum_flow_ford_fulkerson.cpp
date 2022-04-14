#include <bits/stdc++.h>
using namespace std;

/***
 *                  FORD FULKERSON
 * SUMMARY ->
 *        REPEAT UNTIL THERE'S NO PATH TO DEST
 *          CHECK IF THERE'S A PATH FROM THE SOURCE TO DEST
 *             REDUCE THE EDGE WEIGHTS ON THAT PATH BY MIN_WEIGTH AMONG THEM.
 *
 *
 *                      APPROACH

int total_flow = 0;

while(thereIsApth)
   minWeight = minElementInPath()
   total_flow += minWeight;
   reduce_by_minWeight() on path
   thereIsApth = isThereAPath(graph)

                       FINDING THE MIN CUTS
group A: The set of positive nodes that the graph can route through.
These are the edges that start and some nodes of group A , and end at some nodes out side A.

***/

class Graph
{

    vector<vector<int>> graph;
    int s;
    int e;
    int n;
    vector<int> parent;

public:
    Graph(int n, vector<vector<int>> mx, int s, int e)
    {
        this->n = n;
        graph = mx;
        this->s = s;
        parent.resize(n);
        this->e = e;
    }

    int BFS_isThereApath()
    {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        parent[s] = -1;
        visited[s] = true;

        while (!q.empty())
        {
            int p = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (graph[p][i] > 0 && !visited[i])
                {
                    q.push(i);
                    parent[i] = p;
                    visited[i] = true;
                }
            }
        }
        return visited[e];
    }

    int findMaxFlow()
    {
        int max_flow = 0;

        while (BFS_isThereApath())
        {
            // If there's a path then
            // Make a backward flow , Adding to residual graph , substracting to a given graph

            // Find the min among the path flow
            int min_path_flow = INT_MAX;
            for (int i = e; i != s; i = parent[i])
            {
                int u = parent[i];
                min_path_flow = min(min_path_flow, graph[u][i]);
            }

            // You need a parent and a child to start adding and substraing the min_path_flow
            for (int i = e; i != s; i = parent[i])
            {
                int u = parent[i];
                graph[u][i] -= min_path_flow;
                graph[i][u] += min_path_flow;
            }

            max_flow += min_path_flow;
        }

        return max_flow;
    }
};
int main()
{

    vector<vector<int>> gr = {{0, 8, 0, 0, 3, 0},
                              {0, 0, 9, 0, 0, 0},
                              {0, 0, 0, 0, 7, 2},
                              {0, 0, 0, 0, 0, 5},
                              {0, 0, 7, 4, 0, 0},
                              {0, 0, 0, 0, 0, 0}};
     
    int s = 0;
    int e = 5;
    int n = 6;
     Graph graph(n,gr,s,e);
      cout << "Max Flow: " << graph.findMaxFlow() << endl;

    return 0;
}