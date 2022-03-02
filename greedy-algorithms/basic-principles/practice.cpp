#include <bits/stdc++.h>
using namespace std;


int coinChange(vector < int > & coins, int amount) {
  int n = coins.size();


  // 2-D array for storing the results
  int ** dp = new int * [n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new int[amount + 1];
  }


  // Traversing the 2-D dp array
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= amount; j++) {


      // If size of the array is zero and amount is also zero
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      }


      // If size of the array is zero
      else if (i == 0) {
        dp[i][j] = -1;
      }


      // If the amount is zero
      else if (j == 0) {
        dp[i][j] = 0;
      } 
     else {


        // If the value of current coin is less than the amount
        if (j - coins[i - 1] >= 0) {
          if (dp[i][j - coins[i - 1]] != -1 && dp[i - 1][j] != -1)
            dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);


          // If we can't take the current coin for making our amount
          else if (dp[i][j - coins[i - 1]] == -1) {
            dp[i][j] = dp[i - 1][j];
          } 
         else if (dp[i - 1][j] == -1) {
            dp[i][j] = (dp[i][j - coins[i - 1]] + 1);
          }
        } 
       else {
          dp[i][j] = dp[i - 1][j];
        }


      }
    }
  }
 

 for(int i=0;i<=n;i++){
	 for(int j=0;j<=amount;j++) cout<<dp[i][j]<<" ";
	 cout<<"\n";
 }

  return dp[n][amount];
}


int main() {


  vector < int > coins ={2,3};


  int amount = 7;



  // Calling the function
  cout << coinChange(coins, amount);
  return 0;
}