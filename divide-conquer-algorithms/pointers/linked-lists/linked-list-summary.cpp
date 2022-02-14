#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

// Since we want to point to our reference that was passed in. 
// So we should use a pointer. which is characterized by two stars (**)
void insertAtEnd(Node **head, int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    
    struct Node* temp = *head;
   
    if (*head == NULL)
    {
        (*head) = newNode;
        cout << data << endl;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtFront(Node **head, int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    *head = newNode;
}

void traverseList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    struct Node *head;
    // insertAtFront(&head,56);
    insertAtEnd(&head,4);


    insertAtEnd(&head,6);
    // traverseList(head);
    return 0;
}