#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;


int maxScoreAfterNOperations(vector<int> nums) {
   
    priority_queue<tp> gcds;

    int N = nums.size();
    vector<int> state(N, false);

    for (int mask = 0; mask < (1 << N);mask++) {

        vector<int> e;

        for (int j = 0;j < N;j++) {
            if (mask & (1 << j)) {
                e.push_back(j);
            }
        }

        if (e.size() == 2) {
            gcds.push(make_tuple(__gcd(nums[e[0]], nums[e[1]]),e[0], e[1]));
        }
    }

    int k_operations = N / 2;
    int res = 0;

    for (int i = k_operations;i >= 1;i--) {
        int e1 = get<0>(gcds.top());
        int e2 = get<1>(gcds.top());
        int e3 = get<2>(gcds.top());
      cout << e1 << " "<<nums[e2]<< " "<<nums[e3] << endl;

        if(!state[e2] && !state[e3]) {
            res += (e1 * i);  

            state[e2] = 1;
            state[e3] = 1;
        }
        gcds.pop();
    }

    return res;
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6 };
    cout << maxScoreAfterNOperations(nums);
    return 0;
}