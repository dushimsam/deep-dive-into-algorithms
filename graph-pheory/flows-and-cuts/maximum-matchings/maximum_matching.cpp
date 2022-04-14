#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<vector<int>> graph;
    int n;

public:
    Graph(int n, vector<vector<int>> mx)
    {
        this->n = n;
        graph.resize(n + 2, vector<int>(n + 2, 0));
        formGraph(mx);
    }

    void formGraph(vector<vector<int>> mx)
    {

        for (int j = 0; j < (n - 2); j++)
        {
            bool thereIsAllZero = true;
            for (int i = 0; i < (n - 2); i++)
            {
                if (mx[i][j] == 1)
                {
                    thereIsAllZero = false;
                    break;
                }
            }
            if (thereIsAllZero)
                graph[0][j] = 1;
        }

        for (int i = 0; i < (n - 2); i++)
        {
            bool thereIsAllZero = true;
            for (int j = 0; j < (n - 2); j++)
            {
                if (mx[i][j] == 1)
                {
                    thereIsAllZero = false;
                    break;
                }
            }
            if (thereIsAllZero)
                graph[i][n - 1] = 1;
        }

        // copy other elements
        for (int i = 1; i < (n - 1); i++)
        {
            for (int j = 1; j < (n - 1); j++)
            {
                graph[i][j] = mx[i - 1][j - 1];
            }
        }
    }

    void printGraph()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> gr = {
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}};
    int n = 8;
    Graph graph(n, gr);
    graph.printGraph();
    return 0;
}