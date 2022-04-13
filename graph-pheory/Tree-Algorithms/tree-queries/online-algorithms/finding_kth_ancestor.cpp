#include <bits/stdc++.h>
using namespace std;

/***
 *   FIND THE K'th Ancestor of a particular child in a tree.
 *   - The same approach like that used in union find algorithms.
 *   The algorithm can be improved to O(logn) as usual.
***/
class Tree
{
    vector<int> parent;
    int k;

public:
    Tree(vector<int> elems, int k)
    {
        this->parent = elems;
        this->k = k;
    }

    int findAncestor(int currNode, int currCount)
    {
        if (currCount == k)
            return currNode + 1;
        if (parent[currNode] == -1)
            return 0;

        return findAncestor(parent[currNode], currCount + 1);
    }
};

int main()
{
    int n = 8;

    vector<int> par = {-1, 0, 3, 0, 0, 1, 3, 6};
    /***
     *
     *                        1
     *                   /    |   \
     *                  4     5    2
     *                 / \          |
     *                3   7         6
     *                    |
     *                    8
     *   NODE      REPRESENTATIVE_INDEX    PARENT'S INDEX
     *   1              0                   -1
     *   2              1                    0
     *   3              2                    3
     *   4              3                    0
     *   5              4                    0
     *   6              5                    1
     *   7              6                    3
     *   8              7                    6
     * ***/
    int k = 2;
    int startNode = 6;

    Tree tree(par, k);
    cout << "K'th Ancestor of node " << startNode << " is " << tree.findAncestor(startNode - 1, 0);
    return 0;
}