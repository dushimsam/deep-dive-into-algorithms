#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main()
{
    long long n, ans = 1;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}