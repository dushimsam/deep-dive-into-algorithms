#include <bits/stdc++.h>
using namespace std;

int findMinCost(vector<int> steps)
{
    int n = steps.size();
    vector<int> dp(n, 0);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-2] + steps[i-2] , dp[i-1] + steps[i-1]);
    }
    return dp[n-1];
}

int main()
{

    return 0;
}