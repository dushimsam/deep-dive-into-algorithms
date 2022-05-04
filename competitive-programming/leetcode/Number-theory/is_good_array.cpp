#include<bits/stdc++.h>
using namespace std;

int isGoodArray(vector<int> nums) {
    int n = nums.size();
    int gcd = nums[0];

    for (int i = 0;i < n;i++) {
        gcd = __gcd(nums[i], gcd);
        if (i == n - 1 && gcd != 1) return false;
    }

    return true;
}

int main() {
vector<int> nums = {29,6,10};
cout<<isGoodArray(nums);
    return 0;
}
