#include <bits/stdc++.h>
using namespace std;

int main()
{

    // the technique is to separate the even values from the odd values
    long long n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    // start with even numbers
    long long value = 2;

    while (value <= n)
    {
        cout << value << " ";
        value += 2;
    }

    // continue with odd values;
    value = 1;
    while (value <= n)
    {
        cout << value << " ";
        value += 2;
    }

    return 0;
}