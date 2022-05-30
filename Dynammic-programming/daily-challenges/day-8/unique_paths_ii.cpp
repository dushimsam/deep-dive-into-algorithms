#include <bits/stdc++.h>
using namespace std;

// TRUST ME THIS IS THE BEST ALGORITHM EVER 😊😊😊😊

int possibleUniquePaths(vector<vector<int>> matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));

    dp_matrix[0][0] = !matrix[0][0]; // If the first entry's value from the given matrix is 1, It means the path to this entry is 0 vice versa 1..
        

    // fill the first row
    for (int j = 1; j < cols; j++)
    {
        dp_matrix[0][j] = dp_matrix[0][j - 1] != 0 && matrix[0][j] != 1 ? 1 : 0;
    }

    // fill the first column
    for (int i = 1; i < rows; i++)
    {
        dp_matrix[i][0] = dp_matrix[i - 1][0] != 0 && matrix[i][0] != 1 ? 1 : 0;
    }

    // fill the rest of the entries
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // If the entry's value in the given matrix is not equal to 1 then add the two possible path to the current dp entry.
            // which are the left entry and the top entry.

            dp_matrix[i][j] = matrix[i][j] != 1 ? dp_matrix[i - 1][j] + dp_matrix[i][j - 1] : 0;
        }
    }

    return dp_matrix[rows - 1][cols - 1];
}

int main()
{

    return 0;
}