#include<bits/stdc++.h>
using namespace std;


int minCoins(vector<int> coins, int target) {
    int rows = coins.size();
    int cols = target + 1;

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));


    // Fill the first column
    for (int i = 0;i < rows;i++) {
        dp_matrix[i][0] = 0;
    }

    // Fill the first row
    for (int j = 1;j < cols;j++) {
        dp_matrix[0][j] = j;
    }



    for (int i = 1;i < rows;i++) {
        for (int j = 1;j < cols;j++) {
            int prev = dp_matrix[i - 1][j];

            if (j < coins[i]) {
                dp_matrix[i][j] = prev;
            }
            else {
                int curr_val = 1 + dp_matrix[i][(j - coins[i])];
                dp_matrix[i][j] = min(curr_val, prev);

            }
        }
    }



    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) cout << dp_matrix[i][j] << " ";
        cout << "\n";
    }

    return dp_matrix[rows - 1][cols - 1];
}
int main() {
    vector<int> coins = { 4,10,25 };
    int target = 41;
    cout<<"\n\nMin Coins "<< minCoins(coins, target);
    return 0;
}