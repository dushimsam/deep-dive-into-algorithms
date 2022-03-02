#include <bits/stdc++.h>
using namespace std;

int maximizeProfit(vector<int> elements, vector<int> profits, int target)
{
    int rows = elements.size() + 1;
    int cols = target + 1;

    vector<vector<int>> dp_matrix(rows, vector<int>(cols));

    // fill the first row
    for (int i = 0; i < cols; i++)
    {
        dp_matrix[0][i] = -1;
    }

    // fill the first column
    for (int i = 0; i < rows; i++)
    {
        dp_matrix[i][0] = 0;
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (elements[i - 1] > j)
                dp_matrix[i][j] = dp_matrix[i - 1][j];
            else
            {
                int prev = dp_matrix[i - 1][j];
                int sub_res = dp_matrix[i][j - elements[i - 1]];

                if (prev != -1 && sub_res != -1)
                {
                    dp_matrix[i][j] = max(profits[i - 1] + sub_res, prev);
                }
                else if (sub_res == -1)
                {
                    dp_matrix[i][j] = prev;
                }
                else if (prev == -1)
                    dp_matrix[i][j] = profits[i - 1] + sub_res;
            }
        }
    }

    return dp_matrix[rows - 1][cols - 1];
}
int main()
{
    vector<int> rod_lengths = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int target = 4;
    cout << maximizeProfit(rod_lengths, prices, target);
    return 0;
}