#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int maxElem = 0;
    int n = nums.size();

    if (n <= 1)
        return 1;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i] == dp[j])
                    dp[i] += 1;
            }
        }
        maxElem = max(maxElem, dp[i]);
    }
    return maxElem;
}

int main()
{

    return 0;
}