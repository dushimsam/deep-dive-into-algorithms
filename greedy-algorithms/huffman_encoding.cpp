#include<bits/stdc++.h>
using namespace std;


/*
         ALGORITHM FOR IMPLEMENTING THE HUFFMAN ENCODING 

         STEP 1: CREATE THE BINARY TREE
               i. - Create the minHeap using the priority queue.
               ii.- Get first two smallest nodes in the heap.
               iii. - sum up them and create a new node of their "sum" whose child points to them.
               iv. - Repeat (ii && iii) while there still more than one node in the queue.

               // MEANING THAT THE REMAINING NODE WILL BE THE ROOT OF THE TREE.

         STEP 2: TRAVERSE THE TREE PRINTING THE CODE
               - Traverse the tree recursively while printing the codes.
               - The base case for recursion should be where root = NULL


*/

class HuffMan{
struct  Node{
     char letter;
     size_t frequency;
     Node *leftChild = NULL;
     Node * rightChild = NULL;
    
     Node(char letter,size_t frequency):frequency(frequency),letter(letter)
     {}
     ~Node(){
         delete leftChild;
         delete rightChild;
     }
};

struct compare{
    bool operator()(Node* l,Node* r){
        return(l->frequency > r->frequency);
    }
};

priority_queue<Node*,vector<Node*>,compare> nodes;

public: 

     HuffMan(vector<char> chars , vector<size_t> frequencies){
         for(int i=0;chars.size();i++){
             nodes.push(new Node(chars[i],frequencies[i]));
         }
         cout<<"Nodes legnth "<<nodes.size();
     }

     void generateEncoding(){
         while(nodes.size() > 1){
             Node*  leftNode = nodes.top();
             nodes.pop();

             Node* rightNode = nodes.top();
             nodes.pop();


             Node* newNode = new Node('$',leftNode->frequency + rightNode->frequency);
             newNode->leftChild = leftNode;
             newNode->rightChild = rightNode;

             nodes.push(newNode);
         }

          cout<<"nodes length "<<nodes.size();
         printEncoding(nodes.top(),"");
     }


     void printEncoding(Node* root,string encoding){
          if(root == NULL)
             return;
          
          if(root->letter != '$')
          {
              cout<<root->letter<<": "<<root->frequency<<" "<<encoding;
          }
 
          printEncoding(root->leftChild,encoding+"0");
          printEncoding(root->rightChild,encoding+"1");
     }

};


int main(){

	vector<char> data =  { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<size_t> freq = { 5, 9, 12, 13, 16, 45 };
    HuffMan huffMan(data,freq);
    huffMan.generateEncoding();

    return 0;
}