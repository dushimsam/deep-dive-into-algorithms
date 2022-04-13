#include <bits/stdc++.h>
using namespace std;

class Tree
{
    map<int, list<int>> adj;

    int n;
    vector<int> nodeIds;
    vector<int> nodeDegree;
    vector<int> nodeValues;

public:
    Tree(int n, vector<vector<int>> nodeVals)
    {
        this->n = n;
        nodeDegree.resize(n + 1, 0);
        nodeValues.resize(n + 1, 0);

        for (int i = 0; i < nodeVals.size(); i++)
            nodeValues[nodeVals[i][0]] = nodeVals[i][1];
    }

    void addEdge(int w, int x)
    {
        adj[w].push_back(x);
    }

    void DFS(int v)
    {
        nodeDegree[v] = 1;
        nodeIds.push_back(v);

        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            DFS(*it);
            nodeDegree[v] += nodeDegree[*it];
        }
    }

    int findNodeIndex(int nodeId)
    {
        for (int i = 0; i < nodeIds.size(); i++)
        {
            if (nodeIds[i] == nodeId)
                return i;
        }
        return 0;
    }

    int findSubTreeSum(int nodeId)
    {
        int subTreeSum = 0;
        int nodeIndex = findNodeIndex(nodeId);

        int nodeCount = nodeDegree[nodeId];

        for (int i = nodeIndex; i < (nodeCount + nodeIndex); i++)
        {
            subTreeSum += nodeValues[nodeIds[i]];
        }
        return subTreeSum;
    }
};

int main()
{
    int n = 9;

    vector<vector<int>> adj = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {4, 7}, {4, 8}, {4, 9}};
    vector<vector<int>> nodeValues = {{1, 2}, {2, 3}, {3, 5}, {4, 3}, {5, 1}, {6, 4}, {7, 4}, {8, 3}, {9, 1}};

    Tree tree(n + 1, nodeValues);
    for (int i = 0; i < adj.size(); i++)
        tree.addEdge(adj[i][0], adj[i][1]);

    tree.DFS(1);
    int u = 7;

    cout << "\n\n\nSUBTREE SUM OF " << u << " : " << tree.findSubTreeSum(u);
    return 0;
}