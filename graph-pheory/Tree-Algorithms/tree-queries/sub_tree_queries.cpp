#include <bits/stdc++.h>
using namespace std;

class Tree
{
    map<int,list<int>> adj;
   
    int n;
    vector<vector<int>> BI;

public:
    Tree(int n,vector<vector<int>> nodeVals)
    {
        this->n = n;
        BI.resize(3, vector<int>(n, 0));

        for(int i=0;i<nodeVals.size();i++){
            // Assigning the nodes to their corresponding values.
            BI[2][nodeVals[i][0]] = nodeVals[i][1];
        }
    }
    void addEdge(int w, int x)
    {
        adj[w].push_back(x);
    }

    void DFS(int v)
    {
        BI[0][v] = v;
        BI[1][v] = 1;

        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            DFS(*it);
            BI[1][v] += BI[1][*it];
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

    int findSubTreeSum(int node){
        int subTreeSum = 0;

        for(int i=node;i< (BI[1][node]+node) ;i++){
            cout<<"\n"<<BI[2][i];
                 subTreeSum += BI[2][i];
        }
           

        return subTreeSum;
    }
};

int main()
{
    int n = 9;

    vector<vector<int>> adj = {{1, 2}, {1, 3},{1, 4},{1, 5},  {2, 6}, {4, 7}, {4, 8}, {4, 9}};
    vector<vector<int>> nodeValues = {{1,2},{2,3},{3,5},{4,3},{5,1},{6,4},{7,4},{8,3},{9,1}};
   
    Tree tree(n+1,nodeValues);
    for (int i = 0; i < adj.size(); i++)
        tree.addEdge(adj[i][0], adj[i][1]);
    tree.DFS(1);
    tree.printBI();
    
    int u = 4;

    cout<<"\n\n\nSUBTREE SUM OF "<<u << " : "<< tree.findSubTreeSum(u);
    return 0;
}