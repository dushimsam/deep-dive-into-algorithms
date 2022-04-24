#include <bits/stdc++.h>
using namespace std;


int main()
{

  set<int> nums;
  nums.insert(1);
  nums.insert(7);
  nums.insert(1);

  set<int>::iterator it;
  cout << nums.size() <<endl;
  for (it = nums.begin(); it != nums.end();it++)
    cout << *it;
  return 0;
}