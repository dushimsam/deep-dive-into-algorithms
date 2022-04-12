#include <bits/stdc++.h>
using namespace std;

class Tree
{
    map<int, list<int>> adj;
    int n;
    vector<vector<int>> BI;

public:
    Tree(int n)
    {
        this->n = n;
        BI.resize(3, vector<int>(n, 0));
    }
    void addEdge(int w, int x)
    {
        adj[w].push_back(x);
    }

    void DFS(int v)
    {
        BI[0][v] = v;
        BI[2][v] = 1;
        
        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            DFS(*it);
            BI[2][v] += BI[2][*it];
        }
      
    }

    void printBI()
    {
        for (int i = 0; i < BI.size(); i++)
        {
            for (int j = 0; j < BI[0].size(); j++)
            {
                cout << BI[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 9;
    Tree tree(n);
    vector<vector<int>> adj = {{1, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 6}, {4, 7}, {4, 8}, {4, 9}};
    for (int i = 0; i < adj.size(); i++)
        tree.addEdge(adj[i][0], adj[i][1]);
    tree.DFS(1);
    tree.printBI();
    return 0;
}