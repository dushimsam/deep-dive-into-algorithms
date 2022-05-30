#include<bits/stdc++.h>
using namespace std;

int findMaximPossibleSum(vector<int> stack1, vector<int> stack2, vector<int> stack3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0;i < stack1.size();i++) {
        sum1 += stack1[i];
    }

    for (int i = 0;i < stack2.size();i++) {
        sum2 += stack2[i];
    }

    for (int i = 0;i < stack3.size();i++) {
        sum3 += stack3[i];
    }

    int top1=0,top2=0,top3=0;
    
    while(top1 != stack1.size() && top2 != stack2.size() && top3 != stack3.size()) {
        if(sum1 == sum2 && sum3==sum1)
           return sum1;

        if(sum1 >= sum2 && sum1>= sum3)
           sum1 -=stack1[top1++];
        else if(sum2 >= sum1 && sum2>= sum3)
           sum2 -=stack2[top2++];
        else if(sum3 >= sum1 && sum3 >= sum2)
           sum3 -=stack3[top3++];
    }

    return 0;
}

int main() {

    vector<int> stack1 = { 3, 10};
    vector<int> stack2 = { 4, 5 };
    vector<int> stack3 =  { 2, 1 };
    cout<<findMaximPossibleSum(stack1, stack2, stack3);
    return 0;
}