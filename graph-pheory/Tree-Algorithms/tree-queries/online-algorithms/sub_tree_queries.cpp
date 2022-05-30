#include <bits/stdc++.h>
using namespace std;

class Tree
{
    map<int, list<int>> adj;

    int n;
    vector<int> nodeIds;
    vector<int> nodeDegree;
    vector<int> nodeValues;
    vector<int> mp;

public:
    Tree(int n, vector<vector<int>> nodeVals)
    {
        this->n = n;
        nodeDegree.resize(n + 1, 0);
        nodeValues.resize(n + 1, 0);
        mp.resize(n+1,0);

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
    
    void processMp(){
        for(int i=0;i<nodeIds.size();i++){
            mp[nodeIds[i]] =i; 
        }
    }

   
   // Given a subtree parent, Calculate the sum of the value of the nodes in that subtree.
    int processSumQueries(int nodeId)
    {
        int subTreeSum = 0;
        int nodeIndex = mp[nodeId];
        int nodeCount = nodeDegree[nodeId];

        for (int i = nodeIndex; i < (nodeCount + nodeIndex); i++)
        {
            subTreeSum += nodeValues[nodeIds[i]];
        }
        return subTreeSum;
    }

    //Calculate the sum of values on a particular path. From  root - to aparticular child
    int processPathQueryFromRootToAnyNode(int child){
        vector<int> pathSum(n,0);

        // pathSum[0] = nodeValues[nodeIds[0]];
        
        // for(int i=1;i<nodeIds.size();i++){
        //     pathSum[i] = pathSum[i-1] + nodeValues[nodeIds[i]];
        // }
        
        return pathSum[mp[child]];
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
    tree.processMp();

    int u = 7;

    cout << "\n\n\nSUBTREE SUM OF " << u << " : " << tree.processSumQueries(u);
    cout<<"\nPATH SUM BETWEEN 1 AND 9 "<<tree.processPathQueryFromRootToAnyNode(9);
    
    return 0;
}