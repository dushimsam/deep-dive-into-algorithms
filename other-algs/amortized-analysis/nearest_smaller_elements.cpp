#include<bits/stdc++.h>
using namespace std;

/***
 *                 PROBLEM 
 * 
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.

Examples: 

Input:  arr[] = {1, 6, 4, 10, 2, 5}
Output:         {_, 1, 1,  4, 1, 2}
First element ('1') has no element on left side. For 6, 
there is only one smaller element on left side '1'. 
For 10, there are three smaller elements on left side (1,
6 and 4), nearest among the three elements is 4.

Input: arr[] = {1, 3, 0, 2, 5}
Output:        {_, 1, _, 0, 2}

 * 
 * 
 *                     APPROACH
 * 1. stack[]
 * 2. for(i through arr.size())
 *        while(!stack.isEmpty() && stack.top() >= arr[i]) stack.pop()
 * 3.     if(stack.IsEmpty()) cout<<"_"
 * 4.     else  cout<<stack.top(); 
 * 5.     stack.push(arr[i]);
***/

void printNearestElementsForEachElement(vector<int> arr){
    stack<int> S;
    
    for(int i=0;i<arr.size();i++){
        while(!S.empty() && arr[i] <= S.top()){
            S.pop();
        }

        if(S.empty()) cout<<"_ ,";
        else cout<<S.top()<<",";

        S.push(arr[i]);
    }
}
int main(){
vector<int> arr = {1, 6, 4, 10, 2, 5};
printNearestElementsForEachElement(arr);

    return 0;
}