#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int minE) {
    int sum = 0;

    for (int i = 0;i < nums.size();i++) {
        sum += (nums[i] - minE);
    }
    return sum;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> nums;
        int n;
        cin >> n;
        int minE= INT_MAX;

        for (int i = 0;i < n;i++) {
            int curr;
            cin >> curr;
            nums.push_back(curr);
            minE = min(minE, curr);
        }
        cout << solve(nums, minE) << endl;
    }
    return 0;
}