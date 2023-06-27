#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, x, y, res;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        long long k = max(x, y) - 1;
        if (k & 1)
        {
            if (x < y)
                res = k * k + x;
            else
                res = (k * k) + (k * 2) - y + 2;
        }
        else
        {
            if (x < y)
                res = (k * k) + (k * 2) - x + 2;
            else
                res = k * k + y;
        }
        cout << res << endl;
    }
    return 0;
}