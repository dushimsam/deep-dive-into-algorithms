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

int coinChange(vector < int > & coins, int amount) {
	int rows = coins.size()+1;
	int cols = amount + 1;

 vector<vector<int>> dp_matrix(rows,vector<int>(cols));
 // Fill the first row with negative -1's except for the first cell.
 dp_matrix[0][0] = 0;
 
 for(int i=1;i<cols;i++) dp_matrix[0][i] = -1;

 // fill the first column with just zeros.
 for(int i=1;i<rows;i++) dp_matrix[i][0] = 0;


 for(int i =1;i<rows;i++){
	 for(int j=1;j<cols;j++){
		 if(coins[i-1] > j) dp_matrix[i][j] = dp_matrix[i-1][j];
		 else{
			 int sub_res = dp_matrix[i][j-coins[i-1]];
			 int prev = dp_matrix[i-1][j];

			 if(sub_res != -1 && prev != -1){
                    dp_matrix[i][j] = min(sub_res+1,prev);
			 }else if(sub_res == -1) dp_matrix[i][j] = prev;
		   	else if(prev == -1) dp_matrix[i][j] = 1 + sub_res;
		 } 
	 }
 }

 return dp_matrix[rows-1][cols-1];
}

int main() {

    vector<int> coins = { 1,4,9};
    int target = 13;
    cout << coinChange(coins, target);

    return 0;
}