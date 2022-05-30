#include <bits/stdc++.h>
using namespace std;

/***
                              PROGRAM TO CHECK IF A NUMBER IS A PRIME IN O(sqrt(n)) time.

APPROACH
   It turns out that if a number is not a prime number there will numbers a , b
   such that a*b=n and  a <= sqrt(n) and b <= sqrt(n)

   so it means that if we find a number from 2 to sqrt(n) divisible by n
   then that n is not a prime number.
***/
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 12;
    cout << isPrime(n);
    return 0;
}