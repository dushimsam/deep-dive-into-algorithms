#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
    struct Node *root;

public:
    BinaryTree(struct Node *root)
    {
        this->root = root;
    }

    void inorderTraverse(struct Node *node)
    {
        if (node == NULL)
            return;
        inorderTraverse(node->left);
        cout << node->data;
        inorderTraverse(node->right);
    }

    void preOrderTraverse(struct Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data;
        preOrderTraverse(node->left);
        preOrderTraverse(node->right);
    }

    void postOrderTraverse(struct Node *node)
    {
        if (node == NULL)
            return;

        postOrderTraverse(node->left);
        postOrderTraverse(node->right);
        cout << node->data;
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(7);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    
    BinaryTree tree(root);
   cout << "\nPreOrder traversal of binary tree is \n";
    tree.preOrderTraverse(root);
    cout<<endl;

    cout << "\nInOrder traversal of binary tree is \n";
    tree.inorderTraverse(root);
    cout<<endl;

    cout << "\nPostOrder traversal of binary tree is \n";
    tree.postOrderTraverse(root);

    return 0;
}