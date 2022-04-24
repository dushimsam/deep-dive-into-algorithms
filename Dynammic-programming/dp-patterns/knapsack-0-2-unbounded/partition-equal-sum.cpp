#include <bits/stdc++.h>
using namespace std;

/// Knapasack Partition unbounded problem
int partitionSum(vector<int> elements, int target)
{
    int rows = elements.size() + 1;
    int cols = target + 1;
    vector<vector<int>> dp_matrix(rows, vector<int>(cols));

    // fill the first row
    for (int i = 0; i < cols; i++)
    {
        dp_matrix[0][i] = -1;
    }
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
                int sub_res = dp_matrix[i - 1][j - elements[i - 1]];
                
                if (prev != -1 && sub_res != -1)
                    dp_matrix[i][j] = min(sub_res + 1, prev);
                else if (sub_res == -1)
                    dp_matrix[i][j] = prev;
                else if (prev == -1)
                    dp_matrix[i][j] = sub_res + 1;
            }
        }
    }
    return dp_matrix[rows - 1][cols - 1];
}

int main()
{

    vector<int> nums = {1, 2, 3, 5};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    if (sum % 2 != 0)
        cout << " FALSE ";
    else
    {
        if (partitionSum(nums, sum / 2) == -1)
            cout << "FALSE";
        else
            cout << " TRUE";
    }
    return 0;
}