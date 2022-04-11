#include <bits/stdc++.h>
using namespace std;

#define INF 999

/***
 * 
 *  This algorithm is used when we need a shortest distance between each vertices
 *  So the required dsa to be used a matrix.
 * 
 *   APPROACH
 *  UPDATE THE MATRIX k times (k = number of vertices.)
 *  
 * for(let k = 0 until k < V)
 *    for(let i=0 until i < V) 
 *        for(let j= 0 until j< V)
 *           matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j])
***/

class Graph
{
    vector<vector<int>> mt;
    int V, E;

public:
    Graph(int V, vector<vector<int>> input)
    {
        this->V = V;
        mt = input;
    }

    void findShortestPath()
    {
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    mt[i][j] = min(mt[i][j],mt[i][k] + mt[k][j]);
                }
            }
        }

        printMatrix();
    }

    void printMatrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (mt[i][j] == INF)
                    cout << "INF";
                else
                    cout << mt[i][j];
                cout << " ";
            }
            cout << ("\n");
        }
    }
};

main()
{
    vector<vector<int>> input = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};
    Graph graph(4, input);
    graph.findShortestPath();
    return 0;
}