#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, ans = 0, current = 5;
    cin >> n;

    while (current <= n)
    {
        ans += (n / current);
        current *= 5;
    }
    cout << ans << "\n";
    return 0;
}