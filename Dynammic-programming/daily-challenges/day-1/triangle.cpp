#include<bits/stdc++.h>
using namespace std;


int minimumTotal(vector<vector<int>>  triangle_grid) {
    int rows = triangle_grid.size();
    int cols = triangle_grid[rows - 1].size();

    int dp_matrix[rows][cols];

    dp_matrix[0][0] = triangle_grid[0][0];

    for (int i = 0;i < 2;i++) {
        dp_matrix[1][i] = dp_matrix[0][0] + triangle_grid[1][i];
    }

    for (int i = 2;i < rows;i++) {

        for (int j = 0;j < (i + 1);j++) {
            int min_sum = INT_MAX;
            for (int k = 0;k < i;k++) {
                int sum = triangle_grid[i][j] + dp_matrix[i - 1][k];
                
                if (abs(sum) < abs(min_sum))
                    min_sum = sum;
            }
            dp_matrix[i][j] = min_sum;
        }
    }
    int answer = dp_matrix[rows - 1][cols - 1];
    for (int j = 0;j < rows;j++) {
        answer = min(answer, dp_matrix[rows - 1][j]);
    }
    return answer;
}

int main() {

    vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
    cout << minimumTotal(triangle);
    return 0;
}