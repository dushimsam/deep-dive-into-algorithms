#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next = NULL;
    ListNode(int val) : val(val) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    ListNode *head = new ListNode(23);
    head->next = new ListNode(90);
    head->next->next = new ListNode(100);
    head->next->next->next = new ListNode(95);


    cout<< middleNode(head)->val;
    return 0;
}