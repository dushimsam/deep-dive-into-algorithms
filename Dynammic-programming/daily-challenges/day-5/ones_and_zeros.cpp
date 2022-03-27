#include <bits/stdc++.h>
using namespace std;

/***
 * Make a matrix of size (m + 1) x (n + 1)
ret := 0
for i in range 0 to size of strs array
one := 0, zero := 0
for j in range 0 to size of strs[i]
increase one when star[i, j] is 1, or increase zero when it is 0
for j in range m down to 0
for j in range n down to one
dp[j,k] := max of dp[j,k] and 1 + dp[j – zero, k - one]
ret := max of ret and dp[j,k]
return ret
 * 
 * 
 * 
***/

int findMaxForm(vector<string> &strs, int m, int n)
{
    int rows = m + 1;
    int cols = n + 1;
    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));

    for (string str : strs)
    {
        int zeros = 0, ones = 0;
        for (char ch : str)
            if (ch == '0')
                zeros++;
            else
                ones++;
        for (int i = m; i >= zeros; i--)
        {
            for (int j = n; j >= ones; j--)
            {
                dp_matrix[i][j] = max(dp_matrix[i][j], dp_matrix[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp_matrix[m][n];
}
int main()
{

    return 0;
}