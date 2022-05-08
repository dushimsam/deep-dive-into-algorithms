#include<bits/stdc++.h>
typedef vector<int> vi;
using namespace std;

vi findSubArrSum(vi nums,int target){
 int right_pointer = 1;
 int left_pointer = 0;
 int sum = 0;
 while(right_pointer < nums.size()){
      
      while(sum > target && left_pointer < right_pointer){
       sum -= nums[left_pointer];
       left_pointer--;
      }
     
     if(sum == target){
         return {left_pointer,right_pointer};
     }
     right_pointer++;
     sum += nums[right_pointer];
 }

 return {};    
}

int main(){

    return 0;
}