#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef map<int, int> mp;

struct TreeNode
{
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* solve(vi post_order,mp inorder_mp,int start,int end)
{
    if(start > end) return NULL;

     TreeNode* root = new TreeNode(post_order[end++]);
     int mid = inorder_mp[root->val];

     root->right = solve(post_order,inorder_mp,mid+1,end);
     root->left = solve(post_order,inorder_mp,start,mid-1);

     return root;
}

int main()
{
    vi inorder = {};
    vi postorder = {};

    mp inorder_mp;

    for (int i = 0; i < inorder.size(); i++)
        inorder_mp[inorder[i]] = i;
        
    return 0;
}