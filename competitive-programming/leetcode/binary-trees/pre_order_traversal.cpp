#include<bits/stdc++.h>
using namespace std;

/***

Given the root of a binary tree, return the preorder traversal of its nodes' values.
eg:

Input: root = [1,null,2,3]
Output: [1,2,3]

***/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode* root, vector<int>& elems) {
    if (root != NULL) {
        elems.push_back(root->val);
        traverse(root->left, elems);
        traverse(root->right, elems);
    }
}

int main() {
    TreeNode* root;
    vector<int> elems;
    traverse(root, elems);

    return 0;
}