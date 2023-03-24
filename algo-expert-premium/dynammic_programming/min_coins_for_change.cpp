#include <bits/stdc++.h>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    vector<int> minCoins(n + 1, INT_MAX);
    minCoins[0] = 0;

    for (int denom : denoms)
    {
        for (int amount = 1; amount <= n; amount++)
        {
            if (denom <= amount)
            {
                int val;
                if (minCoins[amount - denom] == INT_MAX)
                {
                    val = INT_MAX;
                }
                else
                {
                    val = minCoins[amount - denom] + 1;
                }
                minCoins[amount] = min(minCoins[amount], val);
            }
        }
    }
    return minCoins[n] == INT_MAX ? -1 : minCoins[n];
}

int main()
{
    int n = 7;
    vector<int> denoms = {1, 5, 10};

    // expected result  - 3
    cout << minNumberOfCoinsForChange(n, denoms) << endl;
    return 0;
}