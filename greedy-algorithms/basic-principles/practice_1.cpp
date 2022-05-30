#include <bits/stdc++.h>
using namespace std;



int main(){

int left = 0;
int right = nums.size()-1;
int prev = 0;


while((left <= right) && (nums[left] >= prev || nums[right] >= prev))
{
   if(nums[left] >= prev && nums[left] <= nums[right]) ){
        prev = nums[left];
        left++;
   }else if(nums[right] >= prev){
        prev = nums[right];
        right--;
   }
}
    return 0;
}