#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 * 
 *                       SELECTION SORTING 
 * TIME COMPLEIXTY: 
 *       WORST CASE: O(n^2)
 *       BEST CASE: O(n^2)
 *                        
 *                        APPROACH
 * 1. Pick the minimum element in the right part of the array.
 * 2. Let the min element sit in the current position.
 *
 *  
***/


void printArr(vi arr){
    cout<<"\n";
    for(int e:arr) cout<<e<<" ";
}
void selectionSort(vi arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minEli = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minEli])
                minEli = j;
        }

        int temp = arr[i];
        arr[i] = arr[minEli];
        arr[minEli] = temp;
    }

    printArr(arr);
}

int main()
{
    vi arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    return 0;
}