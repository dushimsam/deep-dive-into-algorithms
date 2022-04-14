#include <bits/stdc++.h>
using namespace std;

/***
                 Euclidian Algorithm O(logn)
                 ------------------
                 The algorithm for finding the GCD of two numbers.
                 GCD: the largest number that can divide the two numbers at the same time.

                it states:
                            gcd(a,b) = {
                                if(b == 0) return a
                                else
                                  return gcd(b, a mod b)
                            }
                Notice that
                           gcd(a,b) = gcd(b,a)
***/

int findGcd(int a, int b)
{
    if (b == 0)
        return a;
    return findGcd(b, a % b);
}

int main()
{
    cout << " GCD OF " << 24 << " AND " << 36 << " IS: " << findGcd(24, 36);
    return 0;
}