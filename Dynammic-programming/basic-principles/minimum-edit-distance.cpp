#include<bits/stdc++.h>
using namespace std;


/***
 *                            ALGORITHM
 * 1. CREATE A DP MATRIX FOR TRACKING
 * 2. LET THE TWO STRING START WHEN THEY ARE ALL NULLS , means ADD EXTRA EMPTY ON THE TWO,  arr[i][0] = 0 -> increment until a.length(),arr[0][j] = 0 -> increment until b.length()
 * 2. if a[i] = b[j] , matrix[i][j] =  matrix[i-1][j-1] // IF they are the same copy the diagonal and then add 1.
 * 3. else  matrix[i][j] = min(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j])+1
 *
***/

int count_minimum_edit_distance(string a, string b) {

    int dp_matrix[a.length() + 1][b.length() + 1];

    for (int i = 0;i <= a.length();i++) {
        dp_matrix[i][0] = i;
    }

    for (int j = 1;j <= b.length();j++) {
        dp_matrix[0][j] = j;
    }


    for (int i = 1;i <= a.length();i++) {

        for (int j = 1;j <= b.length();j++) {
            int diag = dp_matrix[i - 1][j - 1];
            int top = dp_matrix[i - 1][j];
            int left = dp_matrix[i][j - 1];

            if (a[i - 1] == b[j - 1]) dp_matrix[i][j] = diag;
            else dp_matrix[i][j] = min(top, min(left, diag))+1;
        }
    }

    return dp_matrix[a.length()][b.length()];
}

int main() {

    string a = "leetcode";
    string b = "coats";

    cout << count_minimum_edit_distance(a, b);
    return 0;
}