#include <bits/stdc++.h>
using namespace std;

class Tree
{
    map<int, list<int>> treeNodes;
    vector<int> count;

public:
    Tree(int n)
    {
        count.resize(n, 0);
    }

    void addChild(int p, int c)
    {
        treeNodes[p].push_back(c);
    }

    void countNodesForSubtrees(int root)
    {
        list<int>::iterator i;
        count[root] = 1;

        for (i = treeNodes[root].begin(); i != treeNodes[root].end(); i++)
        {
            countNodesForSubtrees(*i);
            count[root] += count[*i];
        }
    }

    void printSubtreeCount()
    {
        countNodesForSubtrees(1);

        cout << " NODE\t\t"
             << "CHILDREN" << endl;
        for (auto node : treeNodes)
        {
            cout << node.first << " : " << count[node.first];
            cout<<endl;
        }
    }
};

main()
{
    int N = 7;
    Tree tree(N);
    vector<vector<int>> edg = {{1, 2}, {1, 4}, {1, 3}, {2, 5}, {2, 6}, {4, 7}};
    for (int i = 0; i < edg.size(); i++)
        tree.addChild(edg[i][0], edg[i][1]);

    tree.printSubtreeCount();
    return 0;
}