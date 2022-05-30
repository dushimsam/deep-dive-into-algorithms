#include<bits/stdc++.h>
using namespace std;


/***
 * 
 * 
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * 
 * 
Input: m = 3, n = 7
Output: 28
 * ***/

int countPossibleMinPaths(int m,int n){
     vector<vector<int>> dp_matrix(m,vector<int>(n,INT_MAX));
     // fill the first row
     for(int i=0;i<n;i++){
            dp_matrix[0][i] = 1;
     }
     // fill in the first column
     for(int i=0;i<m;i++){
            dp_matrix[i][0] = 1;
     }

     // Fill the rest dp[curr] = previous_left + previous_top

     for(int i=1;i<m;i++){
         for(int j=1;j<n;j++) dp_matrix[i][j] = dp_matrix[i-1][j] + dp_matrix[i][j-1];
     }

     return dp_matrix[m-1][n-1];
}

int main(){


    return 0;
}