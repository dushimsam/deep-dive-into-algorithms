#include <bits/stdc++.h>
using namespace std;

/***
 * Given the root of a binary tree and an integer targetSum, return true if
 * the tree has a root-to-leaf path such that adding up all the values along
 * the path equals targetSum.
 *
 ***/
struct TreeNode
{
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



bool isTherePathSum(TreeNode *root, int target)
{
    
    //Keep deducting target as you go down the tree
    int newDiff = target - root->val;

    // It should be the last node in the tree
    if(newDiff == 0 && root->left == NULL && root-> right == NULL) return true;

    //Check if the left child exist AND and return true if it leads to targeted path sum.
    if(root -> left != NULL && isTherePathSum(root->left, newDiff)) return true;

    // As long as the right child is not empty return any value from it's path.
    if(root -> right != NULL) return isTherePathSum(root->right,newDiff);

    return false;
}

int main()
{
TreeNode* root= new TreeNode(1);
root->left = new TreeNode(2);
root -> right = new TreeNode(3);
int target = 3;
cout<<isTherePathSum(root,target);

    return 0;
}