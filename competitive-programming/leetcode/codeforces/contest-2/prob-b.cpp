#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

// Function to display the array
int findIntended(vector<long long> a, int n, long long intended)
{
    int positives = n;
    int xors = 0;

    int result = 0;

    if (n == 2)
    {
        if (a[0] + a[1] == intended || a[0] ^ a[2] == intended)
            return intended;
    }
    
    while (positives > -1)
    {

        for (int i = 0; i < positives; i++)
        {
            result += a[i];
        }

        for (int i = positives; i < n; i++)
        {
            result ^= a[i];
        }

        if (result == intended)
            return result;

        result = 0;
        positives--;
    }
    return result;
}

// Function to find the permutations
void findPermutations(vector<long long> a, long long intended)
{

    vector<long long> temp = a;

    sort(temp.begin(), temp.end());
    do
    {
        long long result = findIntended(temp, temp.size(), intended);
        if (result == intended)
        {
            cout << "Alice\n";
            return;
        }

    } while (next_permutation(temp.begin(), temp.end()));

    cout << "Bob\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<long long> givenInputs;
    long long t, n, initial, intended;

    cin >> t;

    while (t--)
    {
        cin >> n >> initial >> intended;
        int operation_num;
        givenInputs.push_back(initial);

        while (n--)
        {
            cin >> operation_num;
            givenInputs.push_back(operation_num);
        }

        findPermutations(givenInputs, intended);
    }
    return 0;
}