#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root){
    if(root == NULL) return 0;

     
    int leftVal = maxDepth(root->left);
    int rightVal = maxDepth(root -> right);

    int maxChild  = max(leftVal,rightVal);

    return maxChild + 1;
}


int main(){

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->right = new TreeNode(7);
    root->left->left = new TreeNode(15);
    cout << maxDepth(root);

    return 0;
}