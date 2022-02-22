#include<bits/stdc++.h>
using namespace std;

/***
 *                            ALGORITHM
 * 1. CREATE A DP MATRIX FOR TRACKING
 * 2. initialize arr[i][0] = 1
 * 3. if(coins[i] > j ) a[i][j] = a[i-1][j]  else a[i][j] = a[i-1][j]  + a[i][j - coins[i]]
 *
***/
int possible(vector<int> coins, int target) {
    int dp_matrix[coins.size() + 1][target + 1];

    for (int i = 0;i <= coins.size();i++)
        dp_matrix[i][0] = 1;


    for (int j = 0; j <= target; j++)
        dp_matrix[0][j] = 0;

    for (int i = 1;i <= coins.size();i++) {
        for (int j = 1;j <= target;j++) {
            int prev = dp_matrix[i - 1][j];

            if (coins[i - 1] > j) dp_matrix[i][j] = prev;
            else dp_matrix[i][j] = prev + dp_matrix[i][j - coins[i - 1]];
        }
    }

return dp_matrix[coins.size()][target];
}

int main() {
    vector<int> coins = { 2,3,5,10 };
    int target = 13;
    cout << possible(coins, target);
    return 0;
}