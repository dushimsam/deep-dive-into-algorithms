#include<bits/stdc++.h>
using namespace std;


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