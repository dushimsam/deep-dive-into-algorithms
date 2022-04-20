#include <bits/stdc++.h>
using namespace std;

#define ALPHA_MAX 26

struct TrieNode
{
    int val;          // the index of a character which is a distance from the character to character 'a'
    int count = 0;    // Number of strings starting from this character
    int endsHere = 0; // 1 if string ends here or 0 if not.
    TrieNode *child[ALPHA_MAX];
};

class Trie
{
    TrieNode *root;

public:
    TrieNode *getNode(int index)
    {
        TrieNode *newNode = new TrieNode;

        int val = 'a' + index;
        newNode->val = val;
        for (int i = 0; i < ALPHA_MAX; i++)
            newNode->child[i] = NULL;

        return newNode;
    }

    Trie()
    {
        root = getNode('/' - 'a');
    }

    void insert(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a'; // find the distance between 'a' and the character word[i]
       
            if(curr->child[index] == NULL){
                curr->child[index] = getNode(index); // the best place to insert the character
            }

            curr->count +=1;
            curr = curr->child[index]; 
        }
        curr->endsHere = 1;
    }

    bool searchWord(string word){
         TrieNode *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a'; // find the distance between 'a' and the character word[i]
       
            if(curr->child[index] == NULL){
                return false;
            }

            curr->count +=1;
            curr = curr->child[index]; 
        }
        return (curr->endsHere == 1);
    }


    bool startsWith(string prefix){
           TrieNode *curr = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a'; // find the distance between 'a' and the character prefix[i]
       
            if(curr->child[index] == NULL){
                return false;
            }

            curr->count +=1;
            curr = curr->child[index]; 
        }
        return (curr->count > 0);
    }
};

int main()
{
    Trie* trie = new Trie();
    string word = "sam";
    trie->insert(word);

    // TEST INSERT THE WORD
    cout<<trie->searchWord(word);

    //TEST SEARCH HALF WORD .... looking if the last condition holds {(curr->endsHere == 1)}
    cout<<endl<<trie->searchWord("sa");

    // TEST HALF WORD STARTS WITH
    cout<<endl<<trie->startsWith("sa");

    return 0;
}