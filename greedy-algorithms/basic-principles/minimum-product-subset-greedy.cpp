#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minimumProductSubset(vector<int> arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int abs_min_neg = INT_MAX;
    int abs_min_pos = INT_MAX;

    int negatives = 0;
    int positives = 0;
    int contains_zeros = 0;
    int product = 1;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > 0){
            positives++;
            abs_min_pos = min(abs_min_pos,arr[i]);
        }

        else if (arr[i] < 0)
        {
            negatives++;
            abs_min_neg = min(abs_min_neg, abs(arr[i]));
        }

        if (arr[i] == 0)
            contains_zeros = 1;
        else
            product *= arr[i];
    }

    if (!(negatives & 1) && negatives > 0)
    {
        product /= -abs_min_neg;
    }

    if(!negatives && !contains_zeros && positives)
       product = abs_min_pos;
    
    // contains only zeros
    if (!negatives && !positives && contains_zeros)
        product = 0;
 
    //contains zeros and positives only 
    if(!negatives && positives && contains_zeros)
       product = 0;

    return product;
}

int main()
{
    vector<int> parent_vect ={ 0, 0, 0 };

    cout << minimumProductSubset(parent_vect, parent_vect.size());
    return 0;
}

//CHECKS 
// 1. Even number of negatives, remove the absolute minimum_negative
// 2. Only positives return the minimum_positive
// 3. Contains only positives and zeros return zero.
// 4. Contains only zeros return zero.