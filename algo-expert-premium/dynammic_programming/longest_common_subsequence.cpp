#include <bits/stdc++.h>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<vector<char>>> lcs;

    for (int i = 0; i <= len1; i++)
    {
        lcs.push_back(vector<vector<char>>());
        for (int j = 0; j <= len2; j++)
        {
            lcs[i].push_back(vector<char>());
        }
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                vector<char> newString = lcs[i - 1][j - 1];
                newString.push_back(str1[i - 1]);
                lcs[i][j] = newString;
            }
            else
            {
                lcs[i][j] = lcs[i - 1][j].size() > lcs[i][j - 1].size() ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }
    return lcs[len1][len2];
}

int main()
{
    string str1 = "ZXVVYZW";
    string str2 = "XKYKZPW";
    vector<char> res = longestCommonSubsequence(str1, str2);
   
    // Expected result , X,Y,Z,W,
    for(char ch: res) cout << ch << ",";
       
    return 0;
}