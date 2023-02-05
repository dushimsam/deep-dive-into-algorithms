#include<bits/stdc++.h>
using namespace std;


bool zeroSumSubarray(vector<int> nums) {
  
  set<int> st = {0};
  int currSum = 0;

  for(int num : nums){
    currSum += num;
    
    if(st.find(currSum) != st.end()) return true;
    st.insert(currSum);
  }

  return false;
}


int main(){

}