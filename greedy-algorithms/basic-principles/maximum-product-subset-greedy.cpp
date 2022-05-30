#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long maxProductSubset(vector<int> arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr.at(0);
    int negatives = 0;
    int positives = 0;
    long product = 1;
    int contains_zeros = 0;
    int abs_global_min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            positives++;
        else if (arr[i] < 0)
        {
            negatives++;
            abs_global_min = min(abs(arr[i]), abs_global_min);
        }
        if (arr[i] == 0)
        {
            contains_zeros = 1;
        }
        else
        {
            product *= arr[i];
        }
    }

    if (negatives & 1)
        product /= -abs_global_min;

    // CHECK IF THERE IS ONE NEGATIVE AND ZEROS

    if (!positives && negatives == 1 && contains_zeros)
        product = 0;

    // CHECK IF THERE ARE ONLY ZEROS.
    if (!positives && !negatives && contains_zeros)
        product = 0;
    return product;
}

int main()
{
    vector<int> parent_vect = {1, 2, 9, 6, 4};

    cout << maxProductSubset(parent_vect, parent_vect.size());
    return 0;
}