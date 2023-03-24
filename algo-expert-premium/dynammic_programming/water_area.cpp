#include <bits/stdc++.h>
typedef vector<int> vi;

using namespace std;

int waterArea(vector<int> heights)
{
    int size = heights.size();

    vi LEFT_MAX(size, 0);
    vi RIGHT_MAX(size, 0);

    // Fill the max element for each index from the left to right
    for (int i = 1; i < size - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            LEFT_MAX[i] = max(LEFT_MAX[i], heights[j]);
        }
    }

    // Fill the max element for each index from the right to left
    for (int i = size - 2; i > 0; i--)
    {
        for (int j = size - 1; j > i; j--)
        {
            RIGHT_MAX[i] = max(RIGHT_MAX[i], heights[j]);
        }
    }

    // Make the total Sum
    int totalArea = 0;
    for (int i = 1; i < size - 1; i++)
    {
        int minHeight = min(LEFT_MAX[i], RIGHT_MAX[i]);
        if (minHeight - heights[i] >= 0)
            totalArea += minHeight - heights[i];
    }

    return totalArea;
}

int main()
{
    vi arr = {0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};
    // Expected output - 48
    cout << waterArea(arr) << endl;

    return 0;
}