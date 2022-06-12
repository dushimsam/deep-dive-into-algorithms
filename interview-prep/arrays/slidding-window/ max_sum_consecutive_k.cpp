#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(vi arr, int k)
{
    int window_sum = 0;
    int max_sum = 0;

    for (int i = k; i < arr.size(); i++)
    {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
vi arr={45,2,3,4,5};
int k = 2;
cout<< solve(arr,k);

    return 0;
}