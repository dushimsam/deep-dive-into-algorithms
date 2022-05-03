#include<bits/stdc++.h>
using namespace std;



int solve(deque<int> nums) {

  vector<int> pc;
  int prev = 0;

  while (!nums.empty() && (nums.front() >= prev || nums.back() >= prev)) {

    if (nums.front() >= prev && nums.front() <= nums.back()) {
      pc.push_back(nums.front());
      prev = nums.front();
      nums.pop_front();
    }
    else if (nums.back() >= prev) {
      pc.push_back(nums.back());
      prev = nums.back();
      nums.pop_back();
    }
    else if (nums.front() >= prev) {
      pc.push_back(nums.front());
      prev = nums.front();
      nums.pop_front();
    }
  }

  return nums.size();
}



int main() {
int t;
cin >> t;
while(t--) {
 string in;
 cin >> in;
 cout<< solve(in)<<"\n";
}
  return 0;
}