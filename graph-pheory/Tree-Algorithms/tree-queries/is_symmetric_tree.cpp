#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkIsSymmetric(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return (left == right);
    if (left->val != right->val)
        return false;

    return checkIsSymmetric(left->left, right->right) && checkIsSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return checkIsSymmetric(root->left, root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    bool res = isSymmetric(root);

    cout << res;
    return 0;
}