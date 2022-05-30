#include <bits/stdc++.h>
using namespace std;

/***
 *
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or
no elements without changing the order of the remaining elements.
 *
 *
 *
 Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

 *
 * ***/
int findLCS(string s1, string s2)
{
    int rows = s1.length() + 1;
    int cols = s2.length() + 2;

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp_matrix[i][j] = 1 + dp_matrix[i - 1][j - 1];
            else
                dp_matrix[i][j] = max(dp_matrix[i - 1][j], dp_matrix[i][j - 1]);
        }
    }
    return dp_matrix[rows - 1][cols - 1];
}
int main()
{
    string s = "bbbab";
    string originalString = s;
    reverse(s.begin(), s.end());
    string reversedString = s;
    cout<< findLCS(originalString, reversedString);
    return 0;
}
