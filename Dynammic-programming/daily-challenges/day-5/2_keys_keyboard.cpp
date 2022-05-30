#include <bits/stdc++.h>
using namespace std;


int minOpertions(int n)
{
    vector<int> dp(n + 1, 1001);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j > 1; j--)
        {
            if (i % j == 0)
            {
                dp[i] = min(dp[i],dp[j] + (i/j));
            }
        }

        if (dp[i] == 1001)
        {
            dp[i] = i;
        }
    }
    return dp[n];
}


int main()
{

    return 0;
}