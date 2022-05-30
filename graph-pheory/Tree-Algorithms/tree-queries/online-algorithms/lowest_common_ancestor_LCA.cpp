#include <bits/stdc++.h>
using namespace std;

/**** 
 *                                ALGORITHM FOR FINDING THE LOWEST COMMON ANCESTOR
 *                                ------------------------------------------------
 *                 
 *                               STEP 1: CREATE SPARESE_MATRIX[][]
 *                               STEP 2: DFS OF (FORWARD AND BACKWARD)TYPE AND POPULATE EACH NODE ->(TO IT'S CORRESPONDING)-> DEPTH ON A TREE
 *                               // DONE ...
 *                               STEP 3: QUESTION: FIND THE LCA BETWEEN A AND B
 *                                       QUERY APPROACH ->  FIND THE ELEMENT WITH MIN DEPTH BETWEEN A AND B
 *                                                              RETURN MIN_ELEM;
 * 
 ****/

class Tree
{
    map<int, list<int>> adj;
    vector<vector<int>> sparseM;

public:
    Tree(int n)
    {
        // sparseM.resize(2, vector<int>(n + 1));
    }
    void addEdge(int w, int y)
    {
        adj[w].push_back(y);
    }

    void DFS(int v, int level)
    {
        sparseM.push_back({v, level});
        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            DFS(*it, level + 1);
            sparseM.push_back({v, level});
        }
    }

    int findFirstOccur(int node)
    {
        for (int i = 0; i < sparseM.size(); i++)
        {
            if (sparseM[i][0] == node)
                return i;
        }
        return 0;
    }

    int findLCA(int node1, int node2)
    {
        int node1Index = findFirstOccur(node1);
        int node2Index = findFirstOccur(node2);

        // find the element with min depth between two indices
        int minLevel = INT_MAX;
        int minIndex = 0;

        for (int i = min(node1Index, node2Index); i <= max(node1Index, node2Index); i++)
        {

            if (sparseM[i][1] < minLevel)
            {
                minLevel = sparseM[i][1];
                minIndex = i;
            }
        }

        return sparseM[minIndex][0];
    }
};

int main()
{
    int n = 8;
    vector<vector<int>> adj = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {4, 7}, {6, 8}};
    Tree tree(n);
    for (int i = 0; i < adj.size(); i++)
        tree.addEdge(adj[i][0], adj[i][1]);

    tree.DFS(1, 1);
    cout << tree.findLCA(5, 7);

    return 0;
}