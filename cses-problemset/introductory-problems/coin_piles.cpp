#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, a, b;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        string res;
        if ((a + b) % 3 != 0 || a > b * 2 || b > a * 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}