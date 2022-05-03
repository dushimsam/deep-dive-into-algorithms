#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

void  insertAtMiddle(Node **head, int data,int position)
{
    int count = 0;
    while (count < position)
    {
        head = head->next;
        count++;
    }
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode-> next = head -> next -> next;
    head -> next = newNode;
}

bool isArrSorted(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)

        if (arr[i - 1] > arr[i])
            return false;

    return true;
}

vector<int> handleInsert(vector<int> arr){
    int mid = (arr.size() - 1)/2;
    arr
}
string solve(stack<int> arr) {
   


    return
}

int main() {


    return 0;
}