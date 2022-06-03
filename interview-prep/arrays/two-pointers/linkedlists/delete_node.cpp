#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next = NULL;
    ListNode(int val) : val(val) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

void deleteNode(ListNode* &head, int nodeID)
{
    // IF NODE IS AT THE HEAD
    if (head->val == nodeID)
    {
        head = head -> next;
    }
    else
    {
        while (head->next->val != nodeID)
        {
            head = head->next;
        }

        head->next = head->next->next;
    }
}

void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode *head = new ListNode(23);
    head->next = new ListNode(90);
    head->next->next = new ListNode(100);
    head->next->next->next = new ListNode(90);

    deleteNode(head, 23);
    display(head);

    return 0;
}