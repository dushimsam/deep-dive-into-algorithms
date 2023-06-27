#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, sum = 0, currN, totalSum;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> currN;
        sum += currN;
    }

    totalSum = (n * (n + 1)) / 2;
    cout << totalSum - sum << endl;
    return 0;
}