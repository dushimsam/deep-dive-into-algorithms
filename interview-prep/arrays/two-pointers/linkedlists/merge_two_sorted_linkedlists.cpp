#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next = NULL;
    ListNode(){};
    ListNode(int val) : val(val){};
};



ListNode *mergeLists(ListNode *list1, ListNode *list2)
{

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *mergedLists;
    mergedLists = list1;

    if (list2->val < list1->val)
    {
        mergedLists = list2;
        list2 = list2->next;
    }
    else
    {
        list1 = list1->next;
    }

    ListNode *curr = mergedLists;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1)
    {
        curr->next = list1;
    }
    else if (list2)
    {
        curr->next = list2;
    }

    return mergedLists;
}

void displayList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *mergedList = mergeLists(list1, list2);

    displayList(mergedList);
    return 0;
}