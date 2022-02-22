#include<bits/stdc++.h>
using namespace std;

/***
 *                            ALGORITHM
 * 1. CREATE A DP MATRIX FOR TRACKING
 * 2. initialize arr[i][0] = 0 // Since it is the minimum number of ways.
 * 3. Set the first row to incrementing amount [0....len]
 * 3. if(coins[i] > j ) a[i][j] = a[i-1][j]  else a[i][j] = min( a[i-1][j]  , 1 + a[i][j - coins[i]])
 *
***/

int minimum_coins(vector<int> coins, int target) {
    int dp_matrix[coins.size() + 1][target + 1];

    for (int i = 0;i <= coins.size();i++) {
        dp_matrix[i][0] = 0;
    }
    for (int j = 0;j <= target;j++) {
        dp_matrix[0][j] = j;
    }



    for (int i = 1;i <= coins.size();i++) {
        for (int j = 1;j <= target;j++) {
            int prev = dp_matrix[i - 1][j];

            if (coins[i - 1] > j)
                dp_matrix[i][j] = prev;
            else
                dp_matrix[i][j] = min(prev, 1 + dp_matrix[i][j - coins[i - 1]]);
        }
    }

    // for (int i = 0;i < coins.size();i++) {
    //     for (int j = 0;j < target;j++) {
    //         cout << dp_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp_matrix[coins.size()][target];
}
int main() {

    vector<int> coins = { 186,419,83,408};
    int target = 6249;
    cout << minimum_coins(coins, target);

    return 0;
}