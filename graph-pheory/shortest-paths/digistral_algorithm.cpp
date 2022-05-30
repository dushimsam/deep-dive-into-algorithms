#include <bits/stdc++.h>
using namespace std;

/***
 *
 * THE DIFFERENCE WITH BELLMAN-FORD ALORGITHM WE DISCUSSED EALIER IS THAT
 * WE DON'T NEED THE OUTER MOST LOOP THAT LEADS FROM 1-N.
 * THIS IS EFFICIENT ALGORITHM TO BE USED WHEN WE DON'T HAVE NEGATIVE WEIGHTS IN OUR
 * GRAPH.
 * 
 * TIME COMPLEXITY: log(O(n+ mlogm)) // GENERAL VIEW
 * 
 ***/

class Graph
{
    int N;
    vector<tuple<int, int, int>> edge_list;
    vector<int> DIST;

public:
    Graph(int n)
    {
        this->N = n;
        DIST.resize(n, INT_MAX);
        DIST[0] = 0;
    }
    void addEge(int src, int dest, int weight)
    {
        edge_list.push_back(make_tuple(src, dest, weight));
    }

    void findShortestPath()
    {
        for (int j = 0; j < edge_list.size(); j++)
        {
            int src = get<0>(edge_list[j]);
            int dest = get<1>(edge_list[j]);
            int weight = get<2>(edge_list[j]);
            
            // applying relaxing formula
            int newDist = DIST[src] + weight;

            if (newDist < DIST[dest])
                DIST[dest] = newDist;
        }
        printDist();
    }

    void printDist()
    {
        cout << "DISTANCE FROM EDGE 0 to: \n"
             << endl;
        for (int i = 0; i < DIST.size(); i++)
        {
            cout << i << " : " << DIST[i] << endl;
        }
    }
};

int main()
{

    int N = 4;
    Graph graph(N);
    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 4}, {1, 2, 2}, {1, 3, 6}, {2, 3, 3}};
    for (int i = 0; i < edges.size(); i++)
        graph.addEge(edges[i][0], edges[i][1], edges[i][2]);
    graph.findShortestPath();

    return 0;
}