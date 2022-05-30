#include <bits/stdc++.h>
using namespace std;

/***
                      SIEVE ARRAY O(nloglogn) = O(n)

                      - Helps the status of the numbers x between 2 and n
                      if either x is a prime number or it can be found by a multiple of particular prime number.

                      if at particular index i there is 0. Then it means that the number at that index is a prime one. and vice versa
                      if not.
APPROACH

1. for(x = 2 to x = n)
     if(sieve[x] != 0) continue

     for(int u = 2 * x; u <= n;u += x)  // this loop is reached by prime numbers only., We want to form as many combination of this prime numbers as possible
                                        // and associate them to their corresponding value. If the value does not exceed n.

         sieve[u] = x // Meaning that the non-prime number value at index u. Is a multiple of prime number x.
***/

vector<int> buildSieveArray(int n)
{
    vector<int> sieve(n + 1, 0);

    for (int x = 2; x <= n; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x * 2; u <= n; u += x)
        {
            sieve[u] = x;
        }
    }
    return sieve;
}

int main()
{
    int n = 20;
    vector<int> sieve = buildSieveArray(n);
    for (int i = 2; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 2; i < sieve.size(); i++)
        cout << sieve[i] << " ";

    return 0;
}