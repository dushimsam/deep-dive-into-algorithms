#include<bits/stdc++.h>
using namespace std;

vector<int> printSubArray(vector<int> arr, int target){
    int right_pointer = 1;
    int left_pointer = 0;
    int sum = 0;

    while(right_pointer < arr.size()){
         while(sum > target && left_pointer < right_pointer){
             sum -= arr[left_pointer];
             left_pointer++;
         }

         if(sum == target) return {right_pointer, left_pointer};
      
        sum += arr[right_pointer];
        right_pointer++;
    }
}
int main(){

}