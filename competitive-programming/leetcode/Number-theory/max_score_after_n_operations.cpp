#include<bits/stdc++.h>
using namespace std;

int maxScoreAfterNOperations(vector<int> nums) {
    priority_queue<int> gcds;
    int N = nums.size();

    for (int mask = 0; mask < (1 << N);mask++) {
       
        vector<int> e;

        for (int j = 0;j < N;j++) {
            if (mask & (1 << j)) {
                e.push_back(nums[j]);
            }
        }

        if (e.size() == 2) {
            gcds.push(__gcd(e[0], e[1]));
        }
    }

    int k_operations = N/2;
    int res = 0;
    
    for(int i = k_operations;i >= 1;i--) {
        cout<<gcds.top()<<endl;
        res += (gcds.top() * i);
        gcds.pop();
    }

    return res;
}

int main() {
    vector<int> nums = { 3,4,6,8 };
    cout << maxScoreAfterNOperations(nums);
    return 0;
}