#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next = NULL;
    ListNode(){};
    ListNode(int val) : val(val){};
};

ListNode **createList(vector<int> nums)
{

    ListNode **head;
    *head = new ListNode(nums[0]);
     ListNode *traverse;

    for (int i = 1; i < nums.size(); i++)
    {
        traverse = new ListNode(nums[i]);
        traverse->next = traverse->next;
    }
   
   (*head) -> next = traverse;

    return head;
}

ListNode **mergeLists(ListNode *list1, ListNode *list2)
{
    vector<int> nums;

    while (list1 != NULL && list2 != NULL)
    {

        if (list1->val < list2->val)
        {
            nums.push_back(list1->val);
            list1 = list1->next;
        }
        else
        {
            nums.push_back(list2->val);
            list2 = list2->next;
        }
    }

    while (list1 != NULL)
    {
        nums.push_back(list1->val);
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        nums.push_back(list2->val);
        list2 = list2->next;
    }

    return createList(nums);
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

    ListNode **mergedList = mergeLists(list1, list2);

    displayList(*mergedList);
    return 0;
}