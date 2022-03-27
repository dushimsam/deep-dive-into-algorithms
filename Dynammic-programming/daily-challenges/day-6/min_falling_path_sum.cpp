#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, INT_MAX));

    for (int i = 0; i < cols; i++)
    {
        dp_matrix[0][i] = matrix[0][i];
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int curr_cost = matrix[i][j];
            int top_left_path, top_right_path;

            // HANDLING OVERLFOW PROBLEMS
            if (j == 0)
            {
                top_left_path = INT_MAX;
            }
            else
            {
                // COST FROM PREFERING THE TOP LEFT PATH
                top_left_path = dp_matrix[i - 1][j - 1] + curr_cost;
            }
 
             // HANDLING OVERLFOW PROBLEMS
            if (j == cols - 1)
            {
                top_right_path = INT_MAX;
            }
            else
            {
                // COST FROM PREFERING THE TOP RIGHT PATH
                top_right_path = dp_matrix[i - 1][j + 1] + curr_cost;
            }

            int top = dp_matrix[i - 1][j] + curr_cost;

            dp_matrix[i][j] = min(top_left_path, min(top_right_path, top));
        }
    }

    int min_elem = dp_matrix[rows - 1][cols - 1];
    
    for (int j = 0; j < cols; j++)
    {
        min_elem = min(min_elem, dp_matrix[rows - 1][j]);
    }
    return min_elem;
}

int main()
{

    return 0;
}