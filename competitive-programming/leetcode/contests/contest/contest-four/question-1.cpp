#include<bits/stdc++.h>
using namespace std;
/***
 *           
 You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.
  Return a list of all k-distant indices sorted in increasing order.
 * 
***/
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> found_js;
    for (int i = 0;i < nums.size();i++) {
        if (nums[i] == key) found_js.push_back(i);
    }

    vector<int> found_is;
    for (int j = 0;j < nums.size();j++) {
        for (int i = 0;i < found_js.size();i++) {
            if (abs(j - found_js[i]) <= k) { found_is.push_back(j);break; }
        }
    }
    return found_is;
}

int main() {


    return 0;
}