#include<bits/stdc++.h>
using namespace std;

/***
 *                            ALGORITHM
 * 1. CREATE A DP MATRIX FOR TRACKING
 * 2. Initialize the first row and column to zero. || That's the base case
 * 2. if a[i] = b[j] , matrix[i][j] =  matrix[i-1][j-1]+1 // IF they are the same copy the diagonal and then add 1.
 * 3. else  matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])
 *
***/

int largetCommonSubsequence(string a, string b) {
    int target = 5;
    int dp_matrix[a.length() + 1][b.length() + 1];

    for (int i = 0;i <= a.length();i++) {
        dp_matrix[i][0] = 0;
    }


    for (int j = 0;j <= b.length();j++) {
        dp_matrix[0][j] = 0;
    }


    for (int i = 1;i <= a.length();i++) {
        for (int j = 1;j <= b.length();j++) {
            int diag = dp_matrix[i - 1][j - 1];
            int right = dp_matrix[i][j - 1];
            int top = dp_matrix[i - 1][j];

            if (a[i] == b[j]) dp_matrix[i][j] = diag + 1;
            else dp_matrix[i][j] = max(right, top);
        }
    }

    return dp_matrix[a.length()][b.length()];
}

int main() {

string a = "abcdxyz";
string b = "xyzabcd";
cout<<largetCommonSubsequence(a,b);

    return 0;
}
