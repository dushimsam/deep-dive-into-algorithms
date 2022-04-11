#include <bits/stdc++.h>
using namespace std;

/***
 *     1. CREATE THE ADJENCY LIST OF ALL EDJES , DIST[]
 *     2. LET THE DIST[0] = 0
 *     3.
 *     ITERATE FROM 1 TO  (VERTICES - 1)  // TO VERTICES-1 since the last iteration should be reserved for negative cycle checking.
 *       ITERATE THROUGH
 *          EXTRACT FROM CURRENT EDGE
 *            SRC = CURR_EDGE.SRC
 *            DEST = CURR_EDGE.DEST
 *            WEIGHT = CURR_EDGE.WEIGHT
 *
 *            // RELAXING FORMULA
 *            if(DIST[SRC] != INFINITY && DIST[SRC] + WEIGHT < DIST[DEST])
 *                  DIST[DEST] = DIST[SRC] + WEIGHT
 *
 *    4. CHECK FOR NEGATIVE CYCLE
 *
 *
 *  NOTE DOWN :
 *   1. We prefer edge list when working with bellman or dijistral algorithm// Because it will help us to iterate all edges and
 *    to deal with each individually.
 *   2. Vertices are represented as indices
 *   3. DIST[i] represents the shortest distance to aparticular element at index i.
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

    int N = 5;
    Graph graph(N);
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    for (int i = 0; i < edges.size(); i++)
        graph.addEge(edges[i][0], edges[i][1], edges[i][2]);
    graph.findShortestPath();

    return 0;
}