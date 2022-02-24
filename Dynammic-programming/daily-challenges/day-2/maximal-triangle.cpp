#include<bits/stdc++.h>
using  namespace std;

/***                                    QUESTION 
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
                                   
                                   ALGORITHM

if(grid[i-1][j-1] == '1') dp_matrix[i][j] = min(diag,top,left) +1;
***/

int maximalTriangle(vector<vector<char>> grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp_matrix(rows + 1, vector<int>(cols + 1, 0));
    int largest_side = 0;

    for (int i = 1;i <= rows;i++) {
        for (int j = 1;j <= cols;j++) {
            int diag = dp_matrix[i - 1][j - 1];
            int top = dp_matrix[i - 1][j];
            int left = dp_matrix[i][j - 1];

            if (grid[i - 1][j - 1] == '1') {
                dp_matrix[i][j] = min(diag, min(top, left)) + 1;
                largest_side = max(largest_side, dp_matrix[i][j]);
            }

        }
    }

    for (int i = 0;i <= rows;i++) {
        for (int j = 0;j <= cols;j++) cout << dp_matrix[i][j] << " ";
        cout<<endl;
    }

    return largest_side * largest_side;

}
int main() {

    // vector<vector<char>> grid = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    vector<vector<char>> grid = { {'1','1'},{'1','1'},{'0','1'} };

    cout << maximalTriangle(grid);
    return 0;
}