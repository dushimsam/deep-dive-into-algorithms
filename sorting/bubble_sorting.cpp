#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 *
 *                       BUBBLE SORTING
 * TIME COMPLEIXTY: 
 *      WORST CASE : O(n^2)
 *      BEST CASE : O(n)
 * 
 *                        APPROACH
 * 1. DO THIS "N" TIMES
 * 2.    COMPARE THE CURR ELEMENT AND IT'S NEXT
 * 3.          THEN DO APPROPRIATE SWAP
 *
 ***/

void printArr(vi arr)
{
    cout << "\n";
    for (int e : arr)
        cout << e << " ";
}

void bubbleSort(vi arr)
{
    int n = arr.size();

    for (int i = 1; i <= n; i++)
    {
        // "n-1" because i don't want to overthrow at "j+1" at the next line.
        for (int j = 0; j < (n-1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printArr(arr);
}

int main()
{
    vi arr = {64, 25, 12, 22, 11};
    bubbleSort(arr);
    return 0;
}