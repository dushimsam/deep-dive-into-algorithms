#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 Removing the duplicates from the array in the in-place .
 
 We should use the two pointers left and right
 
 ALGO:

 do right+++
    if(arr[left] != arr[right]) left++ , arr[left] = arr[right]

 INSIGHTS:

 Increment the value of the left if and only if the element at right is not equal to that of the
 left.


***/

int solve (vi &arr){
    int left = 0;
    
    for(int right=1;right<arr.size();right++){
       if(arr[left] != arr[right]){
           left++;
           arr[left] = arr[right];
       }
    }
    return (left+1);
}
int main(){
vi arr={3,4,4,5,5,6,7,8,9};
int n = solve(arr);

for(int i=0;i<(n);i++){
    cout<<arr[i]<<" ";
}

    return 0;
}