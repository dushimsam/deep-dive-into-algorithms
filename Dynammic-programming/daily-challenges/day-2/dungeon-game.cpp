#include <bits/stdc++.h>
using namespace std;

/***                     PROBLEM
 * Return the knight's minimum initial health so that he can rescue the princess.
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
 *
 *                         ALGORITHM
 *      Fill the last row
 *      dp_matrix[i][j] = min(dp_matrix[i][j] + grid[i][j],0)
 *      Fill the last column
 *      dp_matrix[i][j] = min(dp_matrix[i+1][j] +  grid[i][j] ,0)
 *      Fill the remaining possitions
 *      dp_matrix[i][j] = min(max(right,bottom) + grid[i][j] , 0)
***/
int calculateMinHp(vector<vector<int>> d)
{
    int rows = d.size();
    int cols = d[0].size();

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));
    dp_matrix[rows - 1][cols - 1] = min(0, d[rows - 1][cols - 1]);

    // Filling the last row
    for (int j = cols - 2; j >= 0; j--)
        dp_matrix[rows - 1][j] = min(d[rows - 1][j] + dp_matrix[rows - 1][j + 1], 0);

    // Filling the last column
    for (int i = rows - 2; i >= 0; i--)
        dp_matrix[i][cols - 1] = min(d[i][cols - 1] + dp_matrix[i + 1][cols - 1], 0);

    for (int i = rows - 2; i >= 0; i++)
    {
        
    }
}
int main()
{
    vector<vector<int>> d = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << calculateMinHp(d);
    return 0;
}