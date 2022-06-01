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

bool isMirror(vector<int> arr){
    int left = 0;
    int right = arr.size()-1;

    while(left < right){
        if(arr[left] != arr[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool isSymmetric(TreeNode * root){
     
     queue<TreeNode*> parts[2];
     queue<TreeNode*>* currQu = &parts[0];
     queue<TreeNode*>* nextQu = &parts[1];
     
     int level = 0;
     
     currQu -> push(root);
     
     vector<int> levelNodes;

     while(!currQu -> empty()){
     TreeNode* currNode = currQu->front();
     currQu->pop();

     if(currNode -> left != NULL) nextQu -> push(currNode -> left);
     if(currNode -> right != NULL) nextQu -> push(currNode -> right);
      
     levelNodes.push_back(currNode -> val);
     
    if(currQu->empty()){
        level++;
        if(!isMirror(levelNodes)) return false;
        
        currQu = &parts[level % 2];
        nextQu = &parts[(level+1) % 2];
    }
     }
     
    return true;
}

int main(){

vector<int> arr={3};
cout<<isMirror(arr);

    return 0;
}