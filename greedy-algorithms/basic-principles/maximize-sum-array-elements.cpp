#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int maximize(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<n;i++)
        sum += (arr[i] * i);
    
    return sum;  
}

int main(){
  vector<int> arr = { 19, 20 };
cout<<maximize(arr,arr.size());
    return 0;
}