#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next = NULL;
    ListNode(int val):val(val) {}
    ListNode(int val,ListNode* next):val(val),next(next){}
};


// METHOD 1 USING SET , HIGH SPACE COMPLEXITY

// bool hasCycle(ListNode* head){
//      set<int> visited;

//      while(head != NULL){
//          if(visited.find(visited.begin(),visited.end(),head->val)) return true;

//          visited.insert(head->val);
//          head = head -> next;
//      } 

//      return false;
// }

// METHOD 2 ,  REDUCED SPACE COMPLEXITY
bool hasCycleImproved(ListNode* head){
     ListNode* walker = head;
     ListNode* runner = head;

     while(walker -> next != NULL && runner -> next -> next != NULL){
         walker = walker -> next;
         runner = runner-> next -> next;

         if(walker == runner) return true;
     }

     return false;
}

int main(){

    ListNode* head = new ListNode(23);
    head -> next = new ListNode(90);
    head -> next -> next = new ListNode(100);
    head -> next -> next -> next = new ListNode(90);

    cout<< hasCycleImproved(head);
    
    return 0;
}