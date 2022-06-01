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

void levelOrder(TreeNode *root)
{
    if(root == NULL) return;

    queue<TreeNode *> queues[2];
    queue<TreeNode *>* currQu = &queues[0];
    queue<TreeNode *>* nextQu = &queues[1];

    currQu->push(root);
    
    int level = 0;

     
    while (!currQu->empty())
    { 
          TreeNode * currNode = currQu->front();
          currQu->pop();
          if(currNode ->left != NULL) nextQu->push(currNode->left);
          if(currNode -> right != NULL) nextQu->push(currNode->right);
          
          cout<<currNode -> val<<" ,";
          if(currQu->empty()){
              cout<<"\n";
              level++;
              currQu = &queues[level % 2];
              nextQu = &queues[(level+1) % 2];
          }
    }
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->right = new TreeNode(7);
    root->left->left = new TreeNode(15);

    levelOrder(root);

    return 0;
}