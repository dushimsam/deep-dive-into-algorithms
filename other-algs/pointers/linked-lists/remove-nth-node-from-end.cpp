#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

void insertNode(Node **head, int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;

    if (*head == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        struct Node *temp = (*head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverse(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
void insertIntoList(Node **head, vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << arr[i] << endl;
        insertNode(head, arr[i]);
    }
}

/***
 *                            ALGORITHM
 * 1. Count the length of the list.
 * 2. Use the formula to get the position of the middle element :: len % 2 == 0 ? (len+2)/2 :(len+1)/2
 * 3.  Traverse the list until you reach the middle element.
 * 4. If you reach there return the current.
 *
 ***/
void removeNthNode(Node *head, int n_th_node)
{

    // variable to count the number of elements in the list
    int len = 0;

    // keep head to be used for next iterations
    struct Node *temp = head;

    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    // Formula to get the middle element after the length is found.
    int k = len - n_th_node;

    // restore the head of the list
    head = temp;
    int i = 1;

    // Iterate until we reach the final element in the list.
    while (i != k)
    {
        head = head->next;
        i++;
    }

    head->next = head->next->next;
}

int main()
{

    struct Node *head = NULL;
    vector<int> list = {1};
    int n_th_node = 1;
    insertIntoList(&head, list);
    removeNthNode(head, n_th_node);
    traverse(head);

    return 0;
}