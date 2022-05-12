#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 *
 *                       INSERTION SORTING
 * TIME COMPLEIXTY:
 *      WORST CASE: O(n^2)
 *      BEST CASE: O(n)
 *
 *                        APPROACH
 * 1. FOR(I = 1 TO N-1)
 *
 * 2.   APPROPRIATE_POSITION = I;
 *
 * 3.     WHILE(APPROPRIATE_POSITION > 0 && ARR[APPROPRIATE_POSITION - 1] > ARR[I])
 * 4.            ARR[APPROPRIATE_POSITION] = ARR[APPROPRIATE_POSITION - 1]
 *               APPROPRIATE_POSITION -=1
 *
 * 5.     ARR[APPROPRIATE_POSITION] = ARR[I]
 *
 ***/

void printArr(vi arr)
{
    cout << "\n";
    for (int e : arr)
        cout << e << " ";
}

void insertionSort(vi arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int CURR_VALUE = arr[i];
        int APPROPRIATE_POSITION = i;

        while (APPROPRIATE_POSITION > 0 && arr[APPROPRIATE_POSITION - 1] > CURR_VALUE)
        {

            // PUSH THE POSITION BACKWARDS INT THE HOLE.
            arr[APPROPRIATE_POSITION] = arr[APPROPRIATE_POSITION - 1];
            APPROPRIATE_POSITION--;
        }

        // Let the element sit here.
        arr[APPROPRIATE_POSITION] = CURR_VALUE;
    }

    printArr(arr);
}

int main()
{
    vi arr = {64, 25, 12, 22, 11};
    insertionSort(arr);

    return 0;
}