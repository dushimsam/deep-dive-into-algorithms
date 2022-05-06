#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/****
 *   APPROACH:
 *  Count all numbers from 1 to the MAX_ELEMETNT , whose multiples belong 
 * 
 * 
 * 
****/
int countDifferentSubsequenceGCDs(vector<int> nums) {
    set<int> gcds;
    int N = nums.size();

    for (ll mask = 0; mask < (1 << N);mask++) {
        vector<int> e;
        for (int j = 0;j < N;j++) {
            if (mask & (1 << j)) {
                e.push_back(nums[j]);

            }
        }
        if (e.size() > 0) {
            int foundGcd = e[0];
            for (int i = 1;i < e.size();i++) {
                foundGcd = __gcd(foundGcd, e[i]);
            }
            gcds.insert(foundGcd);
        }
    }
    return gcds.size();
}

int main() {
    vector<int> nums = { 5,15,40,5,6 };
    cout << countDifferentSubsequenceGCDs(nums);

    return 0;
}