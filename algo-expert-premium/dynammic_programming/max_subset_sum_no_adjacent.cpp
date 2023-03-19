#include <bits/stdc++.h>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
    if (array.size() == 0)
        return 0;

    array[1] = max(array[0], array[1]);
    for (int i = 2; i < array.size(); i++)
    {
        array[i] = max(array[i - 1], array[i - 2] + array[i]);
    }
    return array[array.size() - 1];
}

int main()
{

    vector<int> array = {75, 105, 120, 75, 90, 135};

    // expected result - 330

    cout << maxSubsetSumNoAdjacent(array);

    return 0;
}