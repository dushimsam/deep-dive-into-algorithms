#include<bits/stdc++.h>
using namespace std;

/***
 *                                QUESTION
 *
 *
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*
*
***/

/***                                  ALGORTHIM "DYNAMMIC PROGRAMMING APPROACH"
 * 1. Start counting the min path from a reduced m by n matrix.
 * 2. Create a n by m dp_matrix.
 * 3. Initialize the first row to the respected values considering that you are only going to the right
 *    dp_matrix[0][j] = dp_matrix[0][j-1] + grid[0][j] || = prev_count + current_count
 * 4. Initilize the first column with respected values. You are only going down.
 *    dp_matrix[i][0] = dp_matrix[i-1][0] + grid[i][0]
 * 3. The dp_matrix[i][j] = min(dp_matrix[i-1][j],dp_matrix[i][j-1]) + curr_cell_weight
 * **/

int min_path_sum(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int dp_matrix[rows][cols];

    // Fill the first row.
    for (int j = 0;j < cols;j++) {
        dp_matrix[0][j] = dp_matrix[0][j-1] + grid[0][j];
    }

    // Fill the first col.

    for (int i = 0;i < rows;i++) {
        dp_matrix[i][0] = dp_matrix[i-1][0] + grid[i][0];
    }

    for (int i = 1;i < rows; i++) {
        for (int j = 1; j < cols;j++) {
            dp_matrix[i][j] = min(dp_matrix[i - 1][j], dp_matrix[i][j - 1]) + grid[i][j];
        }
    }

    return dp_matrix[rows - 1][cols - 1];
}
int main() {
    vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };

    cout << min_path_sum(grid);
    return 0;
}