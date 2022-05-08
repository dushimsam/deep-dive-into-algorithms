#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int findMax(vi nums){
  int best = INT_MIN;

  int sum =0;
  for(int i=0;i<nums.size();i++){
     sum = max(nums[i],nums[i]+sum);
     best = max(best,sum);
  }

  return best;
}
int main(){

vi nums = {-1,2,4,-3,5,2,-5,2};
cout<<findMax(nums);

return 0;
}