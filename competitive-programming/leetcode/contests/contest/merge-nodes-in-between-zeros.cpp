#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next = NULL;
};

void insertNode(Node** head, int data)
{
    struct Node* newNode = new Node();
    newNode->data = data;

    if (*head == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        struct Node* temp = (*head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertIntoList(Node** head, vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << arr[i] << endl;
        insertNode(head, arr[i]);
    }
}

void mergeNodes(Node** newListhead, Node* head) {
    int count_sum = 0;
    head = head->next;

    while (head != NULL) {
        if (head->data == 0)
        {
            insertNode(newListhead, count_sum);
            count_sum =0;
        }
        else {
            count_sum += head->data;
        }
        head = head->next;
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

int main() {
    struct Node* head = NULL;
    vector<int> list = { 0,1,0,3,0,2,2,0 };
    insertIntoList(&head, list);

    struct Node* newHead = NULL;
    mergeNodes(&newHead, head);

    traverse(newHead);
}