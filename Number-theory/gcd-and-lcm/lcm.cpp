#include <bits/stdc++.h>
using namespace std;

/***
             LCM - LOWEST COMMON MULTIPLE.

            - The lowest number that can be divided by given numbers. (a , b)

            LCM(a,b) = a*b / GCD(a,b)
***/



// Euclidian algorithm
int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int findLCM(int a, int b)
{
    return (a * b) / findGCD(a, b);
}

int main()
{
    int a = 24;
    int b = 36;

    cout << " LCM OF " << a << " AND " << b << " IS: " << findLCM(24, 36);
    return 0;
}