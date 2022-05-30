#include<bits/stdc++.h>
using namespace std;

// FASTER 100 % SUBMISSIONS ON LEETCODE
int possibleWaysToClimbingStairs(int n){
    if(n == 1 ) return 1;
    vector<int> arr(n+1,0);
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i < (n+1);i++){
     arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main(){


    return 0;
}