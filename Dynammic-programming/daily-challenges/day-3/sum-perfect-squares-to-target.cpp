#include <bits/stdc++.h>
using namespace std;

int countSquareSums(int target)
{
    vector<int> squares;
    for (int i = 1; i <= target; i++)
    {
        int sq = i * i;
        if (sq <= target)
            squares.push_back(sq);
    }
    int rows = squares.size();
    int cols = target + 1;

    vector<vector<int>> dp_matrix(rows, vector<int>(cols));

    for (int i = 0; i < cols; i++)
    {
        dp_matrix[0][i] = i;
    }
    for (int i = 0; i < rows; i++)
    {
        dp_matrix[i][0] = 0;
    }
    

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (squares[i] > j)
                dp_matrix[i][j] = dp_matrix[i-1][j];
            else
            {
                int value = 1 + (dp_matrix[i][j - squares[i]]);
                dp_matrix[i][j] = min(value,dp_matrix[i-1][j]);
            }
        }
    }
    // O(n * m)
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++) cout<<dp_matrix[i][j]<<" ";
    //     cout<<"\n";
    // }
    return dp_matrix[rows-1][cols-1];
}

int main()
{
    cout<<countSquareSums(12);

    return 0;
}